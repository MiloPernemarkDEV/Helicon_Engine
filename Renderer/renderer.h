#pragma once

#if defined(HELICON_RENDERER_USE_VULKAN) && defined(HELICON_RENDERER_USE_OPENGL)
	#error "You can only define one renderer API!"
#elif !defined(HELICON_RENDERER_USE_VULKAN) && !defined(HELICON_RENDERER_USE_OPENGL)
	#error "You must define a renderer API before including renderer.h"
#endif

#if defined(HELICON_RENDERER_USE_VULKAN)
	#include "renderer_vulkan.h"
#elif defined(HELICON_RENDERER_USE_OPENGL)
	// #include "renderer_opengl.h 
#endif

#if defined(HELICON_RENDERER_USE_VULKAN)

inline rend_vk_ctx g_rend_ctx;
inline rend_vk_ctx* rend_get_ctx() {
	return &g_rend_ctx;
}

inline bool renderer_initialize() {
	return rend_init_vk(rend_get_ctx());
}

inline void renderer_shutdown() {
	return rend_shut_vk(rend_get_ctx());
}

inline void renderer_draw_frame() {
	return rend_draw_frame_vk(rend_get_ctx());
}

#elif defined(HELICON_RENDERER_USE_OPENGL)

// OpenGL implementation

#endif

