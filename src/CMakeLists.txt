cmake_minimum_required(VERSION 3.1)
project (spookey)

# Set default CMake build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

# Set compiler if CXX is defined
if($ENV{CXX})
    set(CMAKE_CXX_COMPILER $ENV{CXX})
endif($ENV{CXX})

# Set libraries
set(LIBS pthread)

# Set standard
set (CMAKE_CXX_STANDARD 11)

# Set executable
add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cc)
target_link_libraries(${PROJECT_NAME} ${LIBS})
