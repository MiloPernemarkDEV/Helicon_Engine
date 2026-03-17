#pragma once
#include <vulkan/vulkan.h>
#include "Validation.h"

class InstanceWrapper {
public:

	// Constructors 
	InstanceWrapper() = default;
	InstanceWrapper(Validation& validation, const std::vector<const char*>& extensions);
	~InstanceWrapper() = default;

	VkInstance getInstance() const { return instance_; }

	void setExtensions(const std::vector<const char*>& extensions) {
		extensions_ = extensions;
	}

	void setup();
	void destroy();
	void populateInstanceCreateInfo(
		VkInstanceCreateInfo& createInfo, 
		VkApplicationInfo& appInfo,
		VkDebugUtilsMessengerCreateInfoEXT& debugCreateInfo);
private:
	VkInstance instance_ = VK_NULL_HANDLE;
	Validation* validation_ = nullptr;
	std::vector<const char*> extensions_;
	const std::vector<const char*>& layers_;
};