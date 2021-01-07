add_executable(example_test "example_test.cpp")
target_include_directories(example_test PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(example_test PUBLIC example gtest)
