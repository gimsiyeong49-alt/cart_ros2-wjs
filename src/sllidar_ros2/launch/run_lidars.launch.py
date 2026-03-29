#!/usr/bin/env python3

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.actions import LogInfo
from launch.actions import IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration 
from launch.substitutions import PathJoinSubstitution
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    pass

    return LaunchDescription([

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    get_package_share_directory('sllidar_ros2'),
                    'launch',
                    'sllidar_a3_filtered.launch.py'
                ])
            ]),
            launch_arguments={'serial_port': '/dev/ttyLidar_F',
                              'serial_baudrate': '256000',
                              'frame_id': 'lidar_lF',
                              'inverted': 'false',
                              'angle_compensate': 'True',
                              'scan_mode': 'Sensitivity',
                              'lidar_ns': 'lidar_F',
                              'filter_configfile': 'angle_filter_F.yaml',
                              }.items()

                              ),



        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    get_package_share_directory('sllidar_ros2'),
                    'launch',
                    'sllidar_a3_filtered.launch.py'
                ])
            ]),
            launch_arguments={'serial_port': '/dev/ttyLidar_R',
                              'serial_baudrate': '256000',
                              'frame_id': 'lidar_lR',
                              'inverted': 'false',
                              'angle_compensate': 'true',
                              'scan_mode': 'Sensitivity',
                              'lidar_ns': 'lidar_R',
                              'filter_configfile': 'angle_filter_R.yaml',
                              }.items()
                              ),
                              
	IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    get_package_share_directory('ira_laser_tools'),
                    'launch',
                    'merge_multi.launch.py'
                ])
            ]),
        ),
        
        
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([
                PathJoinSubstitution([
                    get_package_share_directory('roboteq_controller'),
                    'launch',
                    'roboteq_launch.py'
                ])
            ]),
        ),
        
        Node(
            package='arduino_ros2',
            executable='pub_joycmd',
            name='pub_joycmd',
            output='screen',
            ),                 
    ])
    
