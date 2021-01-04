cmake_minimum_required(VERSION 3.0.2)
project(ros_basics_control)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
  ros_basics_msgs
)

catkin_package(
  CATKIN_DEPENDS ros_basics_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(rbcontrollib src/thymio_interface_base.cpp src/thymio_simu_interface.cpp src/gazebo_robot_tracker.cpp src/robot_tracker.cpp)

add_executable(thymio_simu_node src/thymio_simu_node.cpp)
target_link_libraries(thymio_simu_node rbcontrollib ${catkin_LIBRARIES})
add_dependencies(thymio_simu_node ${catkin_EXPORTED_TARGETS} ros_basics_msgs_generate_messages_cpp)

add_executable(thymio_ctrl_node src/thymio_ctrl_node.cpp)
target_link_libraries(thymio_ctrl_node rbcontrollib ${catkin_LIBRARIES})
add_dependencies(thymio_ctrl_node ${catkin_EXPORTED_TARGETS} ros_basics_msgs_generate_messages_cpp)