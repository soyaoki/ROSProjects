# ROS-Enable-Statistics

When you want STATISTICS in ROS, you should set "eneble_statistics" in ROS parameters true [like this](https://github.com/soyaoki/ROS-Enable-Statistics/blob/master/run.launch).

# Usage

`catkin_make`

`souce devel/setup.bash`

`roslaunch run.launch`

`rostopic echo /statistics`
