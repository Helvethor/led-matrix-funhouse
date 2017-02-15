cmake_minimum_required(VERSION 3.0)
project(led-matrix-funhouse)

if(UNIX)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x -DBOOST_LOG_DYN_LINK")
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(text-scroller src/text-scroller.cpp)
target_link_libraries(text-scroller rgbmatrix boost_system boost_filesystem boost_log pthread)

add_executable(fill src/fill.cpp)
target_link_libraries(fill rgbmatrix boost_log pthread)

add_executable(snake src/snake.cpp)
target_link_libraries(snake rgbmatrix boost_log pthread)
