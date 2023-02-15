cmake_minimum_required(VERSION 3.13)
project(unittest_for_tcp_ip)
find_package(GTest)

include_directories(
    ../platform/linux
    ../
)

add_library(source
    ../driver/dummy.c
    ../driver/loopback.c
    ../net.c
    ../util.c
    ../platform/linux/intr.c
)

add_executable(test_dummy test_dummy.cpp)
add_executable(test_net test_net.cpp)
add_executable(test_util test_util.cpp)
add_executable(test_intr test_intr.cpp)
add_executable(test_loopback test_loopback.cpp)

foreach(target test_dummy test_net test_util test_intr test_loopback)
    target_link_libraries(${target} ${GTEST_BOTH_LIBRARIES} pthread source)
    target_include_directories(${target} PUBLIC ${GTEST_INCLUDE_DIRS})
endforeach()