# vulkan

Vulkan experiments

## Study plan

- [Vulkan Tutorial](https://vulkan-tutorial.com/)
- [Vulkan in 30 minutes](https://renderdoc.org/vulkan-in-30-minutes.html)
- [Vulkan Guide](https://vkguide.dev/)
- [GLFW docs](https://www.glfw.org/docs/latest/index.html)

## Setup

- Install dependencies
```
sudo apt install cmake gcc g++ vulkan-tools libvulkan-dev vulkan-validationlayers spirv-tools libglfw3-dev libglm-dev glslc
```
- Run `vkcube` to confirm vulkan tools are set up
- Configure and build
```
mkdir build && cmake .. && make
```
