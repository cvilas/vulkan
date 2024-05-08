#define GLFW_INCLUDE_VULKAN
#include <cstdint>
#include <iostream>
#include <stdexcept>

#include <GLFW/glfw3.h>

class TriangleApp {
public:
  TriangleApp();
  ~TriangleApp();
  void run();

private:
  void initWindow();
  void initVulkan();
  void cleanup();
  void mainLoop();

  static constexpr std::uint32_t WIN_WIDTH = 800;
  static constexpr std::uint32_t WIN_HEIGHT = 600;
  GLFWwindow* window_{ nullptr };
};

int main() {
  try {
    auto app = TriangleApp();
    app.run();
    return EXIT_SUCCESS;
  } catch (const std::exception& ex) {
    std::cout << ex.what();
    return EXIT_FAILURE;
  }
}

TriangleApp::TriangleApp() {
}

TriangleApp::~TriangleApp() {
}

void TriangleApp::run() {
  initWindow();
  initVulkan();
  mainLoop();
  cleanup();
}

void TriangleApp::initWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  window_ = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Vulkan", nullptr, nullptr);
}

void TriangleApp::initVulkan() {
}

void TriangleApp::cleanup() {
  glfwDestroyWindow(window_);
  glfwTerminate();
}

void TriangleApp::mainLoop() {
  while (not glfwWindowShouldClose(window_)) {
    glfwPollEvents();
  }
}
