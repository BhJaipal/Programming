#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <vulkan/vulkan.h>

#include <cstdlib>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <iostream>
#include <map>
#include <optional>
#include <stdexcept>
#include <vector>

struct QueueFamilyIndices {
	std::optional<uint32_t> graphicsFamily;
	bool isComplete() { return graphicsFamily.has_value(); }
};

QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device) {
	QueueFamilyIndices indices;
	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount,
											 nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount,
											 queueFamilies.data());

	int i = 0;
	for (const auto& queueFamily : queueFamilies) {
		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			indices.graphicsFamily = i;
		}
		if (indices.isComplete()) { break; }
		i++;
	}

	return indices;
}

class HelloTriangleApplication {
	VkInstance instance;
	GLFWwindow* window;

   public:
	void run() {
		initVulkan();
		createInstance();
		mainLoop();
		cleanup();
	}

   private:
	void initVulkan() {
		glfwInit();
		pickPhysicalDevice();
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
	}
	void createInstance() {
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		createInfo.enabledLayerCount = 0;
		VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
		if (result != VK_SUCCESS) {
			throw std::runtime_error("failed to create instance!");
		}
	}
	void mainLoop() {
		// uint32_t extensionCount = 0;
		// vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
		// 									   nullptr);
		// std::vector<VkExtensionProperties> extensions(extensionCount);
		// vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount,
		// 									   extensions.data());
		// std::cout << "available extensions:\n";
		// for (const auto& extension : extensions) {
		// 	std::cout << '\t' << extension.extensionName << '\n';
		// }

		while (!glfwWindowShouldClose(window)) { glfwPollEvents(); }
	}
	void cleanup() {
		vkDestroyInstance(instance, nullptr);
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void pickPhysicalDevice() {
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
		if (deviceCount == 0) {
			throw std::runtime_error(
				"failed to find GPUs with Vulkan support!");
		}

		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());
		for (const auto& device : devices) {
			if (isDeviceSuitable(device)) {
				physicalDevice = device;
				break;
			}
		}
		if (physicalDevice == VK_NULL_HANDLE) {
			throw std::runtime_error("failed to find a suitable GPU!");
		}

		std::multimap<int, VkPhysicalDevice> candidates;

		for (const auto& device : devices) {
			int score = rateDeviceSuitability(device);
			candidates.insert(std::make_pair(score, device));
		}

		// Check if the best candidate is suitable at all
		if (candidates.rbegin()->first > 0) {
			physicalDevice = candidates.rbegin()->second;
		} else {
			throw std::runtime_error("failed to find a suitable GPU!");
		}
	}
	int rateDeviceSuitability(VkPhysicalDevice device) {
		int score = 0;
		VkPhysicalDeviceProperties deviceProperties;
		vkGetPhysicalDeviceProperties(device, &deviceProperties);
		VkPhysicalDeviceFeatures deviceFeatures;
		vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

		if (deviceProperties.deviceType ==
			VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
			score += 1000;
		}

		score += deviceProperties.limits.maxImageDimension2D;

		if (!deviceFeatures.geometryShader) { return 0; }

		return score;
	}
	bool isDeviceSuitable(VkPhysicalDevice device) {
		QueueFamilyIndices indices = findQueueFamilies(device);

		return indices.isComplete();
	}
};

int main() {
	HelloTriangleApplication app;

	// 1 0 0 0
	// 0 1 0 0
	// 0 0 1 0
	// 1 2 3 1
	glm::mat4 matrix = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
						0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 2.0f, 3.0f, 1.0f};
	// 1 2 3 1
	glm::vec4 vec = {1.0f, 2.0f, 3.0f, 1.0f};
	// vec * matrix = 2 4 6 1

	// matrix * vec = 1 2 3 15
	auto test = vec * matrix;
	std::cout << "Result: " << test.x << ", " << test.y << ", " << test.z
			  << ", " << test.w << std::endl;

	try {
		app.run();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
