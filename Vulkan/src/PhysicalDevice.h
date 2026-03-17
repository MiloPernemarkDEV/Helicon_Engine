#pragma once

#include <vulkan/vulkan.h>
#include <cstdint>

#include "InstanceWrapper.h"
#include "Surface.h"

class PhysicalDevice {
public:
	
	PhysicalDevice() = default;
	PhysicalDevice(InstanceWrapper& instance, Surface& surface);
	~PhysicalDevice() = default;

	void setup();
	void destroy();

	VkPhysicalDevice getPhysicalDevice() const { return physicalDevice_; }
	bool isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface);

private:
	VkPhysicalDevice physicalDevice_ = VK_NULL_HANDLE;

	InstanceWrapper* instance_;
	Surface* surface_;

};