add_executable(triangle main.cpp)
add_clang_format(triangle)
target_link_libraries(triangle glfw vulkan)
