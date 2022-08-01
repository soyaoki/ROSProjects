# ROS-Arduino-Communication-Practice

```sudo gpasswd --add $USER dialout```

```sudo chmod a+rw /dev/ttyACM0```

```roscore```

```rosrun rosserial_python serial_node.py _port:=/dev/ttyACM0```

```rosrun rviz rviz```

```rostopuc echo marker```


# Ref.

[超音波距離センサとサーボでROSで使えるレンジスキャナを作ってみた](https://qiita.com/atotto/items/6ccd17a4d0f40d51d6e7)

[ROS講座46 ROSでarduinoを使う](https://qiita.com/srs/items/53b1d0a9d574d9ca7752)

[ROS.org/rviz](http://wiki.ros.org/rviz/Tutorials/Markers%3A%20Basic%20Shapes)
