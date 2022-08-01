; Auto-generated. Do not edit!


(cl:in-package custom_msgs-msg)


;//! \htmlinclude container.msg.html

(cl:defclass <container> (roslisp-msg-protocol:ros-message)
  ((vector_name
    :reader vector_name
    :initarg :vector_name
    :type cl:string
    :initform "")
   (vector_len
    :reader vector_len
    :initarg :vector_len
    :type cl:integer
    :initform 0)
   (vector_obj
    :reader vector_obj
    :initarg :vector_obj
    :type (cl:vector custom_msgs-msg:signal)
   :initform (cl:make-array 0 :element-type 'custom_msgs-msg:signal :initial-element (cl:make-instance 'custom_msgs-msg:signal))))
)

(cl:defclass container (<container>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <container>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'container)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name custom_msgs-msg:<container> is deprecated: use custom_msgs-msg:container instead.")))

(cl:ensure-generic-function 'vector_name-val :lambda-list '(m))
(cl:defmethod vector_name-val ((m <container>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:vector_name-val is deprecated.  Use custom_msgs-msg:vector_name instead.")
  (vector_name m))

(cl:ensure-generic-function 'vector_len-val :lambda-list '(m))
(cl:defmethod vector_len-val ((m <container>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:vector_len-val is deprecated.  Use custom_msgs-msg:vector_len instead.")
  (vector_len m))

(cl:ensure-generic-function 'vector_obj-val :lambda-list '(m))
(cl:defmethod vector_obj-val ((m <container>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader custom_msgs-msg:vector_obj-val is deprecated.  Use custom_msgs-msg:vector_obj instead.")
  (vector_obj m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <container>) ostream)
  "Serializes a message object of type '<container>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'vector_name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'vector_name))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vector_len)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'vector_len)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'vector_len)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'vector_len)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'vector_obj))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'vector_obj))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <container>) istream)
  "Deserializes a message object of type '<container>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'vector_name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'vector_name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'vector_len)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'vector_len)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'vector_len)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'vector_len)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'vector_obj) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'vector_obj)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'custom_msgs-msg:signal))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<container>)))
  "Returns string type for a message object of type '<container>"
  "custom_msgs/container")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'container)))
  "Returns string type for a message object of type 'container"
  "custom_msgs/container")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<container>)))
  "Returns md5sum for a message object of type '<container>"
  "0483af8ff08c594e9b9f25c66714449c")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'container)))
  "Returns md5sum for a message object of type 'container"
  "0483af8ff08c594e9b9f25c66714449c")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<container>)))
  "Returns full string definition for message of type '<container>"
  (cl:format cl:nil "string vector_name~%uint32 vector_len~%signal[] vector_obj~%~%================================================================================~%MSG: custom_msgs/signal~%string first_name~%string last_name~%uint8  age~%uint32 scores~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'container)))
  "Returns full string definition for message of type 'container"
  (cl:format cl:nil "string vector_name~%uint32 vector_len~%signal[] vector_obj~%~%================================================================================~%MSG: custom_msgs/signal~%string first_name~%string last_name~%uint8  age~%uint32 scores~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <container>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'vector_name))
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'vector_obj) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <container>))
  "Converts a ROS message object to a list"
  (cl:list 'container
    (cl:cons ':vector_name (vector_name msg))
    (cl:cons ':vector_len (vector_len msg))
    (cl:cons ':vector_obj (vector_obj msg))
))
