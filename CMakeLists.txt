# Check if cmake has the required version
CMAKE_MINIMUM_REQUIRED(VERSION 2.4.3 FATAL_ERROR)
# Needed for cmake 2.6
IF(COMMAND cmake_policy)
	cmake_policy(SET CMP0003 NEW)
ENDIF(COMMAND cmake_policy)

# Set project name
PROJECT(TreeSearch)

set(Boost_ADDITIONAL_VERSIONS "1.47" "1.47.0")
FIND_PACKAGE(Boost 1.42 COMPONENTS program_options REQUIRED)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")


EXEC_PROGRAM(uname ARGS -m OUTPUT_VARIABLE ARCHDIR)


SET(INCLUDES  ${Boost_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_SOURCE_DIR}/include")
INCLUDE_DIRECTORIES(${INCLUDES})


# Set output path for libraries and executables within build directory (makes linking easier...)
SET(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib")
SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/bin")

add_executable(PatternPacker PatternPacker.cc )
add_executable(PatternCheck PatternCheck.cc )

TARGET_LINK_LIBRARIES(PatternPacker ${Boost_LIBRARIES})


