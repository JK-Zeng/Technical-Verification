cmake_minimum_required(VERSION 3.5)
project(technical_verification)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

set(CMAKE_BUILD_TYPE "Release")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(Boost COMPONENTS system REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
add_definitions(-DBOOST_ALL_DYN_LINK)

# find_package(Protobuf REQUIRED)
# include_directories(${Protobuf_INCLUDE_DIRS})

# find_package(Ceres REQUIRED)
# include_directories(${CERES_INCLUDE_DIRS})

find_package(Glog REQUIRED)
# find_package(gflags REQUIRED)
include_directories(
  ${glog_INCLUDE_DIRS} 
  # ${gflags_INCLUDE_DIRS}
  )

find_package(PCL REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITTIONS})

file(GLOB_RECURSE SRC_DIR_LIST CONFIGURE_DEPENDS "src/*.cc" "src/*.cpp" "src/*.c")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/common)

add_executable(${PROJECT_NAME} ${SRC_DIR_LIST})

target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
# target_link_libraries(${PROJECT_NAME} ${Protobuf_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${GLOG_LIBRARIES})
# target_link_libraries(${PROJECT_NAME} ${CERES_LIBRARIES})
# target_link_libraries(${PROJECT_NAME} pthread ethercat)
target_link_libraries(${PROJECT_NAME} ${PCL_LIBRARIES})
