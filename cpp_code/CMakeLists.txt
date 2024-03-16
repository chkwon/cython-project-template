cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(PickupDeliveryProblem VERSION 1.0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(runfoo foo.cpp foo.hpp)

add_library(foo SHARED foo.cpp foo.hpp)