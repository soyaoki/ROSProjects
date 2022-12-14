// Generated by gencpp from file custom_msgs/signal.msg
// DO NOT EDIT!


#ifndef CUSTOM_MSGS_MESSAGE_SIGNAL_H
#define CUSTOM_MSGS_MESSAGE_SIGNAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace custom_msgs
{
template <class ContainerAllocator>
struct signal_
{
  typedef signal_<ContainerAllocator> Type;

  signal_()
    : first_name()
    , last_name()
    , age(0)
    , scores(0)  {
    }
  signal_(const ContainerAllocator& _alloc)
    : first_name(_alloc)
    , last_name(_alloc)
    , age(0)
    , scores(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _first_name_type;
  _first_name_type first_name;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _last_name_type;
  _last_name_type last_name;

   typedef uint8_t _age_type;
  _age_type age;

   typedef uint32_t _scores_type;
  _scores_type scores;





  typedef boost::shared_ptr< ::custom_msgs::signal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::custom_msgs::signal_<ContainerAllocator> const> ConstPtr;

}; // struct signal_

typedef ::custom_msgs::signal_<std::allocator<void> > signal;

typedef boost::shared_ptr< ::custom_msgs::signal > signalPtr;
typedef boost::shared_ptr< ::custom_msgs::signal const> signalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::custom_msgs::signal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::custom_msgs::signal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace custom_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsMessage': True, 'IsFixedSize': False, 'HasHeader': False}
// {'custom_msgs': ['/home/soya/Desktop/ros-msgs-structure/src/custom_msgs/msg'], 'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::signal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::custom_msgs::signal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::signal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::custom_msgs::signal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::signal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::custom_msgs::signal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::custom_msgs::signal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "809a0dd4cedb376d227d76df20aa227a";
  }

  static const char* value(const ::custom_msgs::signal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x809a0dd4cedb376dULL;
  static const uint64_t static_value2 = 0x227d76df20aa227aULL;
};

template<class ContainerAllocator>
struct DataType< ::custom_msgs::signal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "custom_msgs/signal";
  }

  static const char* value(const ::custom_msgs::signal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::custom_msgs::signal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string first_name\n"
"string last_name\n"
"uint8  age\n"
"uint32 scores\n"
;
  }

  static const char* value(const ::custom_msgs::signal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::custom_msgs::signal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.first_name);
      stream.next(m.last_name);
      stream.next(m.age);
      stream.next(m.scores);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct signal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::custom_msgs::signal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::custom_msgs::signal_<ContainerAllocator>& v)
  {
    s << indent << "first_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.first_name);
    s << indent << "last_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.last_name);
    s << indent << "age: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.age);
    s << indent << "scores: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.scores);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CUSTOM_MSGS_MESSAGE_SIGNAL_H
