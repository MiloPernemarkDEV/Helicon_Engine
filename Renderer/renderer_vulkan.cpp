#include "renderer_vulkan.h"
#include "types.h"
#include <vector>
#include <iostream>

#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <vulkan/vulkan.h>
#include <vulkan/vulkan_win32.h>
#endif

std::vector<const char*> get_required_extensions() {
	std::vector<const char*> extensions;

	extensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
#if defined(_WIN32)
	extensions.push_back(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
#endif

	// Optional: add validation layer extension
	// extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);

	return extensions;
}

bool rend_init_vk(rend_vk_ctx* ctx) {

	std::cout << "rend_init Vulkan\n";
	create_instance(ctx->instance);
	return true;
}

void rend_shut_vk(rend_vk_ctx* ctx) {
    
}

void rend_draw_frame_vk(rend_vk_ctx* ctx){


}

void create_instance(VkInstance& instance) {
    VkApplicationInfo app_info{};
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName = "Game Title";
    app_info.pEngineName = "Helicon";
    app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.apiVersion = VK_API_VERSION_1_4;

    VkInstanceCreateInfo create_info{};
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo = &app_info;

    std::vector<const char*> extensions = get_required_extensions();
    create_info.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    create_info.ppEnabledExtensionNames = extensions.data();

    create_info.enabledLayerCount = 0; // add validation layers here if needed

    VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
    if (result != VK_SUCCESS) {
        std::cerr << "Failed to create Vulkan instance, VkResult = " << result << std::endl;
    }
}
