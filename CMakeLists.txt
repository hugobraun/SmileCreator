CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FIND_PACKAGE(OpenCV REQUIRED)

PROJECT(Project)

ADD_EXECUTABLE(smile main.cpp)
TARGET_LINK_LIBRARIES(smile ${OpenCV_LIBS})
