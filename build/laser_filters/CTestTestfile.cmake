# CMake generated Testfile for 
# Source directory: /home/wjs/cart_ros2/src/laser_filters
# Build directory: /home/wjs/cart_ros2/build/laser_filters
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_scan_filter_chain "/usr/bin/python3" "-u" "/opt/ros/galactic/share/ament_cmake_test/cmake/run_test.py" "/home/wjs/cart_ros2/build/laser_filters/test_results/laser_filters/test_scan_filter_chain.gtest.xml" "--package-name" "laser_filters" "--command" "/home/wjs/cart_ros2/build/laser_filters/test_scan_filter_chain" "--ros-args" "--params-file" "/home/wjs/cart_ros2/src/laser_filters/test/test_scan_filter_chain.yaml" "--gtest_output=xml:/home/wjs/cart_ros2/build/laser_filters/test_results/laser_filters/test_scan_filter_chain.gtest.xml")
set_tests_properties(test_scan_filter_chain PROPERTIES  TIMEOUT "60" WORKING_DIRECTORY "/home/wjs/cart_ros2/build/laser_filters" _BACKTRACE_TRIPLES "/opt/ros/galactic/share/ament_cmake_test/cmake/ament_add_test.cmake;124;add_test;/home/wjs/cart_ros2/src/laser_filters/CMakeLists.txt;47;ament_add_test;/home/wjs/cart_ros2/src/laser_filters/CMakeLists.txt;0;")
subdirs("gtest")
