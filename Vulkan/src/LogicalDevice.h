#pragma once

#include <Vulkan/vulkan.h>
#include "Queues.h"
#include "PhysicalDevice.h"
#include "Validation.h"
#include "Surface.h"

class LogicalDevice {
public:
	
	LogicalDevice() = default;
	LogicalDevice(Validation& validation, PhysicalDevice& physicalDevice, Surface& surface);
	~LogicalDevice() = default;

	void setup();
	void destroy();
	VkDevice getDevice() const { return device_; }
private:
	VkDevice device_ = VK_NULL_HANDLE;
	Validation* validation_;
	PhysicalDevice* physicalDevice_;
	Surface* surface_;
};
