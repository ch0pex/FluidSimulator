include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(ftest ftests.cpp)

target_link_libraries(ftest gtest gtest_main)
target_link_libraries(ftest sim)
