cmake_minimum_required(VERSION 3.3)
project(singleODS)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O3")

set(ODS_SOURCE_FILES
        include/Types.hpp
        include/AES.hpp
        include/Bid.h
        include/RAMStore.hpp
        include/ORAM.hpp
        include/AVLTree.h
        include/OMAP.h
        src/AES.cpp
        src/Bid.cpp
        src/RAMStore.cpp
        src/ORAM.cpp
        src/AVLTree.cpp
        src/OMAP.cpp)

add_executable(test_omap test_omap.cpp ${ODS_SOURCE_FILES})
target_link_libraries(test_omap crypto pthread)
