#include "Surface.h"

#include <stdexcept>

Surface::Surface(InstanceWrapper& instance)
	: instance_(&instance)
{
}

void Surface::setup(HWND hWnd, HINSTANCE hInstance) {
	VkWin32SurfaceCreateInfoKHR createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
	createInfo.hwnd = hWnd;
	createInfo.hinstance = hInstance;

	if (vkCreateWin32SurfaceKHR(instance_->getInstance(), &createInfo, nullptr, &surface) != VK_SUCCESS) {
		throw std::runtime_error("failed to create window surface!");
	}
}

void Surface::destroy() {
	vkDestroySurfaceKHR(instance_->getInstance(), surface, nullptr);
}