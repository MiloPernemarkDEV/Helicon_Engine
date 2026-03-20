#pragma once

#include <vulkan/vulkan.h>

struct rend_vk_ctx {
	VkInstance instance;
};

// Interface 
bool rend_init_vk(rend_vk_ctx* ctx);
void rend_shut_vk(rend_vk_ctx* ctx);
void rend_draw_frame_vk(rend_vk_ctx* ctx);

// Internal

void create_instance(VkInstance& vulkan_instance);
