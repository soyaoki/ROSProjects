;; Auto-generated. Do not edit!


(when (boundp 'custom_msgs::container)
  (if (not (find-package "CUSTOM_MSGS"))
    (make-package "CUSTOM_MSGS"))
  (shadow 'container (find-package "CUSTOM_MSGS")))
(unless (find-package "CUSTOM_MSGS::CONTAINER")
  (make-package "CUSTOM_MSGS::CONTAINER"))

(in-package "ROS")
;;//! \htmlinclude container.msg.html


(defclass custom_msgs::container
  :super ros::object
  :slots (_vector_name _vector_len _vector_obj ))

(defmethod custom_msgs::container
  (:init
   (&key
    ((:vector_name __vector_name) "")
    ((:vector_len __vector_len) 0)
    ((:vector_obj __vector_obj) (let (r) (dotimes (i 0) (push (instance custom_msgs::signal :init) r)) r))
    )
   (send-super :init)
   (setq _vector_name (string __vector_name))
   (setq _vector_len (round __vector_len))
   (setq _vector_obj __vector_obj)
   self)
  (:vector_name
   (&optional __vector_name)
   (if __vector_name (setq _vector_name __vector_name)) _vector_name)
  (:vector_len
   (&optional __vector_len)
   (if __vector_len (setq _vector_len __vector_len)) _vector_len)
  (:vector_obj
   (&rest __vector_obj)
   (if (keywordp (car __vector_obj))
       (send* _vector_obj __vector_obj)
     (progn
       (if __vector_obj (setq _vector_obj (car __vector_obj)))
       _vector_obj)))
  (:serialization-length
   ()
   (+
    ;; string _vector_name
    4 (length _vector_name)
    ;; uint32 _vector_len
    4
    ;; custom_msgs/signal[] _vector_obj
    (apply #'+ (send-all _vector_obj :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _vector_name
       (write-long (length _vector_name) s) (princ _vector_name s)
     ;; uint32 _vector_len
       (write-long _vector_len s)
     ;; custom_msgs/signal[] _vector_obj
     (write-long (length _vector_obj) s)
     (dolist (elem _vector_obj)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _vector_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _vector_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint32 _vector_len
     (setq _vector_len (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; custom_msgs/signal[] _vector_obj
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _vector_obj (let (r) (dotimes (i n) (push (instance custom_msgs::signal :init) r)) r))
     (dolist (elem- _vector_obj)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get custom_msgs::container :md5sum-) "0483af8ff08c594e9b9f25c66714449c")
(setf (get custom_msgs::container :datatype-) "custom_msgs/container")
(setf (get custom_msgs::container :definition-)
      "string vector_name
uint32 vector_len
signal[] vector_obj

================================================================================
MSG: custom_msgs/signal
string first_name
string last_name
uint8  age
uint32 scores

")



(provide :custom_msgs/container "0483af8ff08c594e9b9f25c66714449c")


