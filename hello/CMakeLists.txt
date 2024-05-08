add_executable(hello main.cpp)
add_clang_format(hello)
target_link_libraries(hello glfw vulkan)
