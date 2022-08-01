# ros-two-node-in-one-package

"nodes.cpp" and "nodes_2.cpp" didn't work. There were 2 main function, so multiple definition erro was happened.

But "nodes.cpp", "nodes.py" and "nodes_2.py" worked together as expected.

# Step

(1)add_executable(${PROJECT_NAME} src/nodes.cpp src/nodes.py src/nodes_2.py "ADD OTHER FILES")

(2)"rosrun nodes nodes", "rosrun nodes nodes.py" and "rosrun nodes nodes_2.py"
