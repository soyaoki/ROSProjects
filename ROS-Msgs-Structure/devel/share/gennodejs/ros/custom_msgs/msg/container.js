// Auto-generated. Do not edit!

// (in-package custom_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let signal = require('./signal.js');

//-----------------------------------------------------------

class container {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.vector_name = null;
      this.vector_len = null;
      this.vector_obj = null;
    }
    else {
      if (initObj.hasOwnProperty('vector_name')) {
        this.vector_name = initObj.vector_name
      }
      else {
        this.vector_name = '';
      }
      if (initObj.hasOwnProperty('vector_len')) {
        this.vector_len = initObj.vector_len
      }
      else {
        this.vector_len = 0;
      }
      if (initObj.hasOwnProperty('vector_obj')) {
        this.vector_obj = initObj.vector_obj
      }
      else {
        this.vector_obj = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type container
    // Serialize message field [vector_name]
    bufferOffset = _serializer.string(obj.vector_name, buffer, bufferOffset);
    // Serialize message field [vector_len]
    bufferOffset = _serializer.uint32(obj.vector_len, buffer, bufferOffset);
    // Serialize message field [vector_obj]
    // Serialize the length for message field [vector_obj]
    bufferOffset = _serializer.uint32(obj.vector_obj.length, buffer, bufferOffset);
    obj.vector_obj.forEach((val) => {
      bufferOffset = signal.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type container
    let len;
    let data = new container(null);
    // Deserialize message field [vector_name]
    data.vector_name = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [vector_len]
    data.vector_len = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [vector_obj]
    // Deserialize array length for message field [vector_obj]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.vector_obj = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.vector_obj[i] = signal.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.vector_name.length;
    object.vector_obj.forEach((val) => {
      length += signal.getMessageSize(val);
    });
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'custom_msgs/container';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0483af8ff08c594e9b9f25c66714449c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string vector_name
    uint32 vector_len
    signal[] vector_obj
    
    ================================================================================
    MSG: custom_msgs/signal
    string first_name
    string last_name
    uint8  age
    uint32 scores
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new container(null);
    if (msg.vector_name !== undefined) {
      resolved.vector_name = msg.vector_name;
    }
    else {
      resolved.vector_name = ''
    }

    if (msg.vector_len !== undefined) {
      resolved.vector_len = msg.vector_len;
    }
    else {
      resolved.vector_len = 0
    }

    if (msg.vector_obj !== undefined) {
      resolved.vector_obj = new Array(msg.vector_obj.length);
      for (let i = 0; i < resolved.vector_obj.length; ++i) {
        resolved.vector_obj[i] = signal.Resolve(msg.vector_obj[i]);
      }
    }
    else {
      resolved.vector_obj = []
    }

    return resolved;
    }
};

module.exports = container;
