cmake_minimum_required(VERSION 3.0.2)
project(smb_hl_control)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages

find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
)


## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   sensor_msgs
# )


catkin_package()


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(sub_node src/smb_highlevel_controller.cpp)  ##node_name and location

target_link_libraries(sub_node ${catkin_LIBRARIES})
