#pragma once

#define WIN32_LEAN_AND_MEAN
#include "Windows.h"
#include "InstanceWrapper.h"

#include <vulkan/vulkan.h>
#include <vulkan/vulkan_win32.h>

#include "HcWin32Window.h"

class Surface {
public:
	Surface() = default;
	Surface(InstanceWrapper& instance);
	~Surface() = default;

	void setup(HWND hWnd, HINSTANCE hInstance);
	void destroy();

	VkSurfaceKHR getSurface() const { return surface; }
private:
	VkSurfaceKHR surface = VK_NULL_HANDLE;
	InstanceWrapper* instance_;
	

};