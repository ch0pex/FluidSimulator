include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(utest block_test.cpp grid_test.cpp proargs_test.cpp)

target_link_libraries(utest gtest gtest_main)
target_link_libraries(utest sim)
