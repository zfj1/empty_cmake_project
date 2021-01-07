## Define libraries
add_library(example "Example.cpp")
target_include_directories(example PUBLIC ${CMAKE_SOURCE_DIR}/include)

