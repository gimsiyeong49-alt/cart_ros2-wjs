import os

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    use_sim_time = LaunchConfiguration('use_sim_time')
    config_dir = LaunchConfiguration('configuration_directory')
    config_basename = LaunchConfiguration('configuration_basename')

    pkg_dir = get_package_share_directory("agv_mapping")
    default_config_dir = os.path.join(pkg_dir, 'config')
    default_basename = 'agv_cartographer_2d.lua'

    declare_use_sim_time = DeclareLaunchArgument(
        'use_sim_time', default_value='false'
    )
    declare_config_dir = DeclareLaunchArgument(
        'configuration_directory', default_value=default_config_dir
    )
    declare_basename = DeclareLaunchArgument(
        'configuration_basename', default_value=default_basename
    )

    cartographer_node = Node(
        package='cartographer_ros',
        executable='cartographer_node',
        name='cartographer_node',
        output='screen',
        arguments=[
            '-configuration_directory', config_dir,
            '-configuration_basename', config_basename,
        ],
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool)
        }],
        remappings=[
            ('/scan', '/scan_multi'),
            ('/odom', '/odom'),
            ('/imu',  '/imu/data'),
        ],
    )

    occupancy_grid_node = Node(
        package='cartographer_ros',
        executable='occupancy_grid_node',
        name='occupancy_grid_node',
        output='screen',
        arguments=[
            '-resolution', '0.05',
            '-publish_period_sec', '1.0',
        ],
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool)
        }],
    )

    return LaunchDescription([
        declare_use_sim_time,
        declare_config_dir,
        declare_basename,
        cartographer_node,
        occupancy_grid_node,
    ])

