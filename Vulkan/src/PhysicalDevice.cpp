#include "PhysicalDevice.h"
#include <stdexcept>
#include <vector>
#include "Queues.h"


PhysicalDevice::PhysicalDevice(InstanceWrapper& instance, Surface& surface)
	: instance_(&instance), surface_(&surface)
{
}

void PhysicalDevice::setup() {
	std::uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance_->getInstance(), &deviceCount, nullptr);

	if (deviceCount == 0) {
		throw std::runtime_error("failed to find GPUs with Vulkan support");
	}

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance_->getInstance(), &deviceCount, devices.data());

	for (const auto& device : devices) {
		if (isDeviceSuitable(device, surface_->getSurface())) {
			physicalDevice_ = device;
			break;
		}

		VkPhysicalDeviceProperties deviceProperties;
		vkGetPhysicalDeviceProperties(device, &deviceProperties);
		VkPhysicalDeviceFeatures deviceFeatures;
		vkGetPhysicalDeviceFeatures(device, &deviceFeatures);
	}

	if (physicalDevice_ == VK_NULL_HANDLE) {
		throw std::runtime_error("failed to find a suitable GPU!");
	}
}

bool PhysicalDevice::isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface) {
	QueueFamilyIndices indices = findQueueFamilies(device, surface_->getSurface());

	return indices.isComplete();
}
