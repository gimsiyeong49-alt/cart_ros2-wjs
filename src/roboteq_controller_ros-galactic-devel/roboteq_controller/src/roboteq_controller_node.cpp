#include "roboteq_controller/roboteq_controller_node.h"

// static const std::string tag {"[RoboteQ] "};
static const std::string tag {""};

void RoboteqDriver::declare(){
	declare_parameter<std::string>("serial_port", "dev/ttyUSB0");
	declare_parameter("baudrate", 112500);
	declare_parameter("closed_loop", false);
	declare_parameter("diff_drive_mode", false);
	declare_parameter("wheel_circumference", 0.0);
	declare_parameter("track_width", 0.0);
	declare_parameter("max_rpm", 0.0);
	declare_parameter<int>("frequency", 0);
	declare_parameter<std::string>("cmd_vel_topic", "cmd_vel");
}

void RoboteqDriver::init(){
	RCLCPP_INFO(get_logger(), "Creating");
	get_parameter("frequency", frequency_);

	get_parameter("serial_port", serial_port_);
	get_parameter("baudrate", baudrate_);

	get_parameter("closed_loop", closed_loop_);
	get_parameter("diff_drive_mode", diff_drive_mode_);
	
	get_parameter("wheel_circumference", wheel_circumference_);
	get_parameter("track_width", track_width_);
	get_parameter("max_rpm", max_rpm_);
	get_parameter("cmd_vel_topic", cmd_vel_topic_);

	RCLCPP_INFO_STREAM(this->get_logger(),tag << "cmd_vel:" << cmd_vel_topic_);

	if (closed_loop_){
		RCLCPP_INFO_STREAM(this->get_logger(),tag << "In CLOSED-LOOP mode!!!! serial port:" << serial_port_);
	}
	else{
		RCLCPP_INFO_STREAM(this->get_logger(),tag << "In OPEN-LOOP mode!!!!");
	}

	if (wheel_circumference_ <=0.0 ){
		RCLCPP_ERROR_STREAM(this->get_logger(),tag << "Inproper configuration! wheel_circumference need to be greater than zero.");
	}
	if (track_width_ <=0.0 ){
		RCLCPP_ERROR_STREAM(this->get_logger(),tag << "Inproper configuration! track_width need to be greater than zero.");
	}
	if ( max_rpm_ <=0.0 ){
		RCLCPP_ERROR_STREAM(this->get_logger(),tag << "Inproper configuration! max_rpm need to be greater than zero.");
	}

	if (frequency_ <= 0.0){
		RCLCPP_ERROR_STREAM(this->get_logger(),tag << "Inproper configuration! \'frequency\' need to be greater than zero.");
	}

	auto param_interface = this->get_node_parameters_interface();
	std::map<std::string, rclcpp::ParameterValue> params = param_interface->get_parameter_overrides();

	RCLCPP_INFO_STREAM(this->get_logger(), tag << "queries:" );

	for (auto iter = params.begin(); iter != params.end(); iter++){
		std::size_t pos = iter->first.find("query");
		if (pos != std::string::npos && 
			iter->second.get_type() == rclcpp::ParameterType::PARAMETER_STRING){
  			std::string topic = iter->first.substr (pos+ 6);    
			auto query = iter->second.to_value_msg().string_value;
			
			queries_[topic] =  query;
			RCLCPP_INFO(this->get_logger(), "%15s : %s",  topic.c_str(), query.c_str() );
		}
	}
}


RoboteqDriver::RoboteqDriver(const rclcpp::NodeOptions &options): Node("roboteq_controller", options),
	wheel_circumference_(0.),
	track_width_(0.),
	max_rpm_(0.),
	frequency_(0),
	serial_port_("dev/ttyUSB0"),
	baudrate_(112500),
	closed_loop_(false),
	diff_drive_mode_(false),
	cmd_vel_topic_("cmd_vel"){
	
	declare();
	init();

	if (diff_drive_mode_){
		cmd_vel_sub_ = create_subscription<geometry_msgs::msg::Twist>(
										cmd_vel_topic_, rclcpp::SystemDefaultsQoS(),
										std::bind(&RoboteqDriver::cmdVelCallback, this, std::placeholders::_1));
	}
	else{
		cmd_vel_sub_ = create_subscription<geometry_msgs::msg::Twist>(
										cmd_vel_topic_, rclcpp::SystemDefaultsQoS(),
										std::bind(&RoboteqDriver::powerCmdCallback, this, std::placeholders::_1));
	}

	try{
		ser_.setPort(serial_port_);
		ser_.setBaudrate(baudrate_);
		serial::Timeout timeout = serial::Timeout::simpleTimeout(1000);
		ser_.setTimeout(timeout);
		ser_.open();
	}
	catch (serial::IOException &e){
		RCLCPP_ERROR_STREAM(this->get_logger(),tag << "Unable to open port " << serial_port_);
		rclcpp::shutdown();
	}

	if (ser_.isOpen()){
		RCLCPP_INFO_STREAM(this->get_logger(),tag << "Serial Port " << serial_port_ << " initialized");
	}
	else{
		RCLCPP_INFO_STREAM(this->get_logger(),tag << "Serial Port " << serial_port_ << " is not open");
		rclcpp::shutdown();
	}

	cmdSetup();

	run();
}


void RoboteqDriver::cmdSetup(){
	ser_.write("!G 1 0\r");
	ser_.write("!G 2 0\r");
	ser_.write("!S 1 0\r");
	ser_.write("!S 2 0\r");
	ser_.flush();

	ser_.write("^RWD 1000\r");

	if (!closed_loop_){
		ser_.write("^MMOD 1 0\r");
		ser_.write("^MMOD 2 0\r");
		ser_.flush();
	}
	else{
		ser_.write("^MMOD 1 1\r");
		ser_.write("^MMOD 2 1\r");
		ser_.flush();
	}

	std::stringstream right_enccmd;
	std::stringstream left_enccmd;
	right_enccmd << "^EPPR 1 " << 1024 << "\r";
	left_enccmd << "^EPPR 2 " << 1024 << "\r";
	ser_.write(right_enccmd.str());
	ser_.write(left_enccmd.str());
	ser_.flush();
}


void RoboteqDriver::run(){
	std::stringstream ss0, ss1;
	ss0 << "^echof 1_";
	ss1 << "# c_/\"DH?\",\"?\"";

	for (auto item : queries_){
		RCLCPP_INFO_STREAM(this->get_logger(),tag << "Publish topic: " << item.first);
		query_pub_.push_back(create_publisher<roboteq_interfaces::msg::ChannelValues>(item.first, 100));

		std::string cmd = item.second;
		ss1 << cmd << "_";
	}

	ss1 << "# " << frequency_ << "_";
	
	ser_.write(ss0.str());
	ser_.write(ss1.str());
	ser_.flush();
	

    serial_read_pub_ = create_publisher<std_msgs::msg::String>("read", rclcpp::SystemDefaultsQoS());

	std::chrono::duration<int, std::milli> dt (1000/frequency_);
	timer_pub_ = create_wall_timer(dt, std::bind(&RoboteqDriver::queryCallback, this) );
}


void RoboteqDriver::powerCmdCallback(const geometry_msgs::msg::Twist &msg){
	std::stringstream cmd_str;
	if (closed_loop_){
		cmd_str << "!S 1"
				<< " " << msg.linear.x << "_"
				<< "!S 2"
				<< " " << msg.angular.z << "_";
	}
	else{
		cmd_str << "!G 1"
				<< " " << msg.linear.x << "_"
				<< "!G 2"
				<< " " << msg.angular.z << "_";
	}
	ser_.write(cmd_str.str());
	ser_.flush();
	RCLCPP_INFO(this->get_logger(),"[ROBOTEQ] left: %9.3f right: %9.3f", msg.linear.x, msg.angular.z);
}


void RoboteqDriver::cmdVelCallback(const geometry_msgs::msg::Twist &msg){
	float right_speed = msg.linear.x + track_width_ * msg.angular.z / 2.0;
	float left_speed  = msg.linear.x - track_width_ * msg.angular.z / 2.0;
	
	std::stringstream cmd_str;
	if (!closed_loop_){
		float right_power = right_speed *1000.0 *60.0/ (wheel_circumference_ * max_rpm_);
		float left_power  = left_speed  *1000.0 *60.0/ (wheel_circumference_ * max_rpm_);
	
		RCLCPP_INFO(this->get_logger(),"[ROBOTEQ] left: %9d right: %9d", (int)left_power, (int)right_power);
		
		cmd_str << "!G 1"
				<< " " << (int)left_power << "_"
				<< "!G 2"
				<< " " << (int)right_power << "_";
	}
	else{
		int32_t right_rpm = right_speed *60.0 / wheel_circumference_;
		int32_t left_rpm  = left_speed  *60.0 / wheel_circumference_;

		RCLCPP_INFO(this->get_logger(),"[ROBOTEQ] left: %9d right: %9d", left_rpm, right_rpm);
		cmd_str << "!S 1"
				<< " " << left_rpm << "_"
				<< "!S 2"
				<< " " << right_rpm << "_";
	}

	ser_.write(cmd_str.str());
	ser_.flush();
}


void RoboteqDriver::queryCallback(){
	auto current_time = this->now();
	if (ser_.available()){
		std_msgs::msg::String result;

		std::lock_guard<std::mutex> lock(locker);

		result.data = ser_.read(ser_.available());

		serial_read_pub_->publish(result);
		
		boost::replace_all(result.data, "\r", "");
		boost::replace_all(result.data, "+", "");

		std::vector<std::string> fields;
		
		boost::split(fields, result.data, boost::algorithm::is_any_of("D"));
		if (fields.size() < 2){

			RCLCPP_ERROR_STREAM(this->get_logger(),tag << "Empty data:{" << result.data << "}");
		}
		else if (fields.size() >= 2){
			std::vector<std::string> fields_H;
			for (int i = fields.size() - 1; i >= 0; i--){
				if (fields[i][0] == 'H'){
					try{
						fields_H.clear();
						boost::split(fields_H, fields[i], boost::algorithm::is_any_of("?"));
						if ( fields_H.size() >= query_pub_.size() + 1){
							break;
						}
					}
					catch (const std::exception &e){
						std::cerr << e.what() << '\n';
						RCLCPP_ERROR_STREAM(this->get_logger(),tag << "Finding query output in :" << fields[i]);
						continue;
					}
				}
			}

			if (fields_H.size() > 0 && fields_H[0] == "H"){
				for (int i = 0; i < fields_H.size() - 1; ++i){
					std::vector<std::string> sub_fields_H;
					boost::split(sub_fields_H, fields_H[i + 1], boost::algorithm::is_any_of(":"));
					
					roboteq_interfaces::msg::ChannelValues msg;
					msg.header.stamp = current_time;

					for (int j = 0; j < sub_fields_H.size(); j++){
						try{
							int v = boost::lexical_cast<int>(sub_fields_H[j]);
							msg.value.push_back(-v);   // raw 엔코더 출력 전체 반전
						}
						catch (const std::exception &e){
							RCLCPP_ERROR_STREAM(this->get_logger(),tag << "Garbage data on Serial");
							RCLCPP_ERROR_STREAM(this->get_logger(), result.data);
							RCLCPP_ERROR_STREAM(this->get_logger(), e.what());
							std::cerr << e.what() << '\n';
						}
					}
					query_pub_[i]->publish(msg);
				}
			}
		}
		else{
			RCLCPP_WARN_STREAM(this->get_logger(),tag << "Unknown:{" << result.data << "}");
		}
	}
}


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<RoboteqDriver>());
  rclcpp::shutdown();
  return 0;
}
