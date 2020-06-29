cmake_minimum_required(VERSION 3.5)
project(ros_tutorials)

set(CMAKE_CXX_STANDARD 14)

#find_package(OpenCV REQUIRED)
find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        sensor_msgs
        message_generation
        )

## Declare ROS messages and services
add_message_files(DIRECTORY msg FILES Score.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
        INCLUDE_DIRS
        LIBRARIES
        CATKIN_DEPENDS roscpp std_msgs sensor_msgs message_runtime
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(publisher_node src/publisher_example.cpp)
target_link_libraries(publisher_node ${catkin_LIBRARIES})
add_dependencies(publisher_node ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(subscriber_node src/subscriber_example.cpp)
target_link_libraries(subscriber_node ${catkin_LIBRARIES})
add_dependencies(subscriber_node ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(pub_sub_node src/sub_and_pub_example.cpp)
target_link_libraries(pub_sub_node ${catkin_LIBRARIES})
add_dependencies(pub_sub_node ${${PROJECT_NAME}_EXPORTED_TARGETS})



## Header files to include
#add_libary(${LIBRARY_NAME} STATIC ${FILENAME})
#install(TARGETS ${LIBRARY_NAME} DESTINATION include)

### Build nodes
#include_directories(include ${catkin_INCLUDE_DIRS})
#add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_FILENAME})
#target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME} ${catkin_LIBRARIES})
#add_dependencies(${EXECUTABLE_NAME} ${LIBRARY_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS})


