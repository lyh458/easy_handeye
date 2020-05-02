
#pragma once

#include <ros/node_handle.h>
#include <easy_handeye_msgs/SampleList.h>
#include <easy_handeye_msgs/HandeyeCalibration.h>

namespace easy_handeye_rviz_plugins
{
class RobotMovementsClient
{
public:
  RobotMovementsClient();

  std::vector<std::string> moveitGroups();

  bool selectMoveitGroup(const std::string& group);

private:
  std::string active_calibration_namespace = "";

  ros::ServiceClient check_starting_pose_client;
  ros::ServiceClient enumerate_target_poses_client;
  ros::ServiceClient select_target_pose_client;
  ros::ServiceClient plan_to_target_pose_client;
  ros::ServiceClient execute_plan_client;

  ros::NodeHandle nh;
};

};  // namespace easy_handeye_rviz_plugins
