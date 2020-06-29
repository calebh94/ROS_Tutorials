cmake_minimum_required(VERSION 3.5)
project(ROS_Tutorials)

set(CMAKE_CXX_STANDARD 14)

#find_package(OpenCV REQUIRED)
find_package(catkin REQUIRED COMPONENTS
        roscpp
        std_msgs
        sensor_msgs
        )

catkin_package(
        INCLUDE_DIRS include
        LIBRARIES
        CATKIN_DEPENDS roscpp std_msgs sensor_msgs
)

## Header files to include
#add_libary(${LIBRARY_NAME} STATIC ${FILENAME})
#install(TARGETS ${LIBRARY_NAME} DESTINATION include)

### Build nodes
#include_directories(include ${catkin_INCLUDE_DIRS})
#add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_FILENAME})
#target_link_libraries(${EXECUTABLE_NAME} ${LIBRARY_NAME} ${catkin_LIBRARIES})
#add_dependencies(${EXECUTABLE_NAME} ${LIBRARY_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS})


