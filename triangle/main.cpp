#define GLFW_INCLUDE_VULKAN
#include <cstdint>
#include <iostream>
#include <stdexcept>

#include <GLFW/glfw3.h>

//=================================================================================================
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
  void createInstance();

  static constexpr std::uint32_t WIN_WIDTH = 800;
  static constexpr std::uint32_t WIN_HEIGHT = 600;
  GLFWwindow* window_{ nullptr };
  VkInstance instance_{};
};

//=================================================================================================
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

//-------------------------------------------------------------------------------------------------
TriangleApp::TriangleApp() {
}

//-------------------------------------------------------------------------------------------------
TriangleApp::~TriangleApp() {
}

//-------------------------------------------------------------------------------------------------
void TriangleApp::run() {
  initWindow();
  initVulkan();
  mainLoop();
  cleanup();
}

//-------------------------------------------------------------------------------------------------
void TriangleApp::initWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  window_ = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "Vulkan", nullptr, nullptr);
}

//-------------------------------------------------------------------------------------------------
void TriangleApp::initVulkan() {
  createInstance();
}

//-------------------------------------------------------------------------------------------------
void TriangleApp::createInstance() {
  VkApplicationInfo app_info{};
  app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  app_info.pApplicationName = "Hello Triangle";
  app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.pEngineName = "No Engine";
  app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  app_info.apiVersion = VK_API_VERSION_1_0;

  VkInstanceCreateInfo create_info{};
  create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  create_info.pApplicationInfo = &app_info;

  std::uint32_t glfw_extension_count = 0;
  const char** glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);
  create_info.enabledExtensionCount = glfw_extension_count;
  create_info.ppEnabledExtensionNames = glfw_extensions;

  create_info.enabledLayerCount = 0;

  if (vkCreateInstance(&create_info, nullptr, &instance_) != VK_SUCCESS) {
    throw std::runtime_error("failed to create instance!");
  }
}

//-------------------------------------------------------------------------------------------------
void TriangleApp::cleanup() {
  vkDestroyInstance(instance_, nullptr);
  glfwDestroyWindow(window_);
  glfwTerminate();
}

//-------------------------------------------------------------------------------------------------
void TriangleApp::mainLoop() {
  while (not glfwWindowShouldClose(window_)) {
    glfwPollEvents();
  }
}
