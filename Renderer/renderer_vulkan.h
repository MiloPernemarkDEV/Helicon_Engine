#pragma once

#include <vulkan/vulkan.h>

struct renderer_vulkan {
	VkInstance vulkan_instance;
};

// Interface 
bool renderer_initialize_vulkan();
void renderer_shutdown_vulkan();
void renderer_draw_frame_vulkan();

// Internal

void create_instance(VkInstance& vulkan_instance);
