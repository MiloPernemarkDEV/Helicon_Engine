#include "LogicalDevice.h"
#include "Queues.h"

LogicalDevice::LogicalDevice(Validation& validation, PhysicalDevice& physicalDevice, Surface& surface) 
	: validation_(&validation), physicalDevice_(&physicalDevice), surface_(&surface)
{}

void LogicalDevice::setup()
{
	QueueFamilyIndices indices = findQueueFamilies(physicalDevice_->getPhysicalDevice(), surface_->getSurface());

	VkDeviceQueueCreateInfo queueCreateInfo{};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = indices.graphicsFamily.value();
	queueCreateInfo.queueCount = 1;

	float queuePriority = 1.0f;
	queueCreateInfo.pQueuePriorities = &queuePriority;

	VkPhysicalDeviceFeatures deviceFeatures{};

	VkDeviceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

	createInfo.pQueueCreateInfos = &queueCreateInfo;
	createInfo.queueCreateInfoCount = 1;

	createInfo.pEnabledFeatures = &deviceFeatures;

	createInfo.enabledExtensionCount = 0;

	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validation_->getValidationlayers().size());
		createInfo.ppEnabledLayerNames = validation_->getValidationlayers().data();
	}
	else {
		createInfo.enabledLayerCount = 0;
	}

	if (vkCreateDevice(physicalDevice_->getPhysicalDevice(), &createInfo, nullptr, &device_) != VK_SUCCESS) {
		throw std::runtime_error("failed to create logical device!");
	}

	vkGetDeviceQueue(device_, indices.graphicsFamily.value(), 0, &graphicsQueue);

}

void LogicalDevice::destroy() {
	vkDestroyDevice(device_, nullptr);

}


