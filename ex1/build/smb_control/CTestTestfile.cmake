# CMake generated Testfile for 
# Source directory: /home/utsab/Workspaces/ETH_ROS/ex1/src/smb_common/smb_common/smb_control
# Build directory: /home/utsab/Workspaces/ETH_ROS/ex1/build/smb_control
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_smb_control_roslaunch-check_launch "/home/utsab/Workspaces/ETH_ROS/ex1/build/smb_control/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/utsab/Workspaces/ETH_ROS/ex1/build/smb_control/test_results/smb_control/roslaunch-check_launch.xml" "--return-code" "/usr/bin/cmake -E make_directory /home/utsab/Workspaces/ETH_ROS/ex1/build/smb_control/test_results/smb_control" "/opt/ros/noetic/share/roslaunch/cmake/../scripts/roslaunch-check -o \"/home/utsab/Workspaces/ETH_ROS/ex1/build/smb_control/test_results/smb_control/roslaunch-check_launch.xml\" \"/home/utsab/Workspaces/ETH_ROS/ex1/src/smb_common/smb_common/smb_control/launch\" ")
set_tests_properties(_ctest_smb_control_roslaunch-check_launch PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/roslaunch/cmake/roslaunch-extras.cmake;66;catkin_run_tests_target;/home/utsab/Workspaces/ETH_ROS/ex1/src/smb_common/smb_common/smb_control/CMakeLists.txt;8;roslaunch_add_file_check;/home/utsab/Workspaces/ETH_ROS/ex1/src/smb_common/smb_common/smb_control/CMakeLists.txt;0;")
subdirs("gtest")
