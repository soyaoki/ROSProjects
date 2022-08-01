# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from custom_msgs/container.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import custom_msgs.msg

class container(genpy.Message):
  _md5sum = "0483af8ff08c594e9b9f25c66714449c"
  _type = "custom_msgs/container"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """string vector_name
uint32 vector_len
signal[] vector_obj

================================================================================
MSG: custom_msgs/signal
string first_name
string last_name
uint8  age
uint32 scores
"""
  __slots__ = ['vector_name','vector_len','vector_obj']
  _slot_types = ['string','uint32','custom_msgs/signal[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       vector_name,vector_len,vector_obj

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(container, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.vector_name is None:
        self.vector_name = ''
      if self.vector_len is None:
        self.vector_len = 0
      if self.vector_obj is None:
        self.vector_obj = []
    else:
      self.vector_name = ''
      self.vector_len = 0
      self.vector_obj = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self.vector_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_I().pack(self.vector_len))
      length = len(self.vector_obj)
      buff.write(_struct_I.pack(length))
      for val1 in self.vector_obj:
        _x = val1.first_name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1.last_name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_BI().pack(_x.age, _x.scores))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.vector_obj is None:
        self.vector_obj = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.vector_name = str[start:end].decode('utf-8')
      else:
        self.vector_name = str[start:end]
      start = end
      end += 4
      (self.vector_len,) = _get_struct_I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.vector_obj = []
      for i in range(0, length):
        val1 = custom_msgs.msg.signal()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.first_name = str[start:end].decode('utf-8')
        else:
          val1.first_name = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.last_name = str[start:end].decode('utf-8')
        else:
          val1.last_name = str[start:end]
        _x = val1
        start = end
        end += 5
        (_x.age, _x.scores,) = _get_struct_BI().unpack(str[start:end])
        self.vector_obj.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self.vector_name
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_I().pack(self.vector_len))
      length = len(self.vector_obj)
      buff.write(_struct_I.pack(length))
      for val1 in self.vector_obj:
        _x = val1.first_name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1.last_name
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.pack('<I%ss'%length, length, _x))
        _x = val1
        buff.write(_get_struct_BI().pack(_x.age, _x.scores))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.vector_obj is None:
        self.vector_obj = None
      end = 0
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.vector_name = str[start:end].decode('utf-8')
      else:
        self.vector_name = str[start:end]
      start = end
      end += 4
      (self.vector_len,) = _get_struct_I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.vector_obj = []
      for i in range(0, length):
        val1 = custom_msgs.msg.signal()
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.first_name = str[start:end].decode('utf-8')
        else:
          val1.first_name = str[start:end]
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          val1.last_name = str[start:end].decode('utf-8')
        else:
          val1.last_name = str[start:end]
        _x = val1
        start = end
        end += 5
        (_x.age, _x.scores,) = _get_struct_BI().unpack(str[start:end])
        self.vector_obj.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_BI = None
def _get_struct_BI():
    global _struct_BI
    if _struct_BI is None:
        _struct_BI = struct.Struct("<BI")
    return _struct_BI