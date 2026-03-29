include "map_builder.lua"
include "trajectory_builder.lua"

options = {
  map_builder = MAP_BUILDER,
  trajectory_builder = TRAJECTORY_BUILDER,

  map_frame = "map",

  -- ✅ IMU 쓸 때는 base_footprint보다 base_link가 안전 (imu_link 있으면 그게 베스트)
  tracking_frame = "imu_link",

  published_frame = "base_footprint",
  odom_frame = "odom",

  provide_odom_frame = true,
  publish_frame_projected_to_2d = true,

  use_odometry = true,
  use_nav_sat = false,
  use_landmarks = false,

  num_laser_scans = 1,
  num_multi_echo_laser_scans = 0,
  num_subdivisions_per_laser_scan = 1,
  num_point_clouds = 0,

  lookup_transform_timeout_sec = 0.2,

  submap_publish_period_sec = 0.5,
  pose_publish_period_sec = 0.02,
  trajectory_publish_period_sec = 0.05,

  rangefinder_sampling_ratio = 1.0,
  odometry_sampling_ratio = 1.0,

  -- ✅ /imu/data가 315Hz라서 그대로 다 받으면 부담 → 다운샘플 추천
  imu_sampling_ratio = 0.1,

  fixed_frame_pose_sampling_ratio = 1.0,
  landmarks_sampling_ratio = 1.0,
}

MAP_BUILDER.use_trajectory_builder_2d = true

TRAJECTORY_BUILDER_2D.min_range = 0.12
TRAJECTORY_BUILDER_2D.max_range = 6.0
TRAJECTORY_BUILDER_2D.missing_data_ray_length = 6.0

-- ✅ IMU ON
TRAJECTORY_BUILDER_2D.use_imu_data = true
TRAJECTORY_BUILDER_2D.imu_gravity_time_constant = 10.0

TRAJECTORY_BUILDER_2D.submaps.num_range_data = 90
POSE_GRAPH.optimize_every_n_nodes = 35

return options

