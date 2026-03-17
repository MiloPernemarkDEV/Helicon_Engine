#include "renderer_vulkan.h"

bool renderer_initialize_vulkan() {



	return true;
}

void renderer_shutdown_vulkan() {


}

void renderer_draw_frame_vulkan() {


}

//
// Internal implementations
//
void create_instance(VkInstance& instance)
{
	VkApplicationInfo app_info{};
	app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	app_info.pApplicationName = "Game Title";
	app_info.pEngineName = "Helicon";
	app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0); 
	app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	app_info.apiVersion = VK_MAKE_VERSION(1, 4, 335);

	VkInstanceCreateInfo create_info{};
	create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	create_info.pApplicationInfo = &app_info;

	vkCreateInstance(&create_info, nullptr, &instance);
}
