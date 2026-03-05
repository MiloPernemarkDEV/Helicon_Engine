#pragma once

#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif

#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#elif defined(__GNU__) || defined(__clang__)
#define FORCE_INLINE inline __attribute__((always_inline))
#else 
#define FORCE_INLINE inline
#endif

constexpr bool HC_SUCCESS = true;
constexpr bool HC_FAILURE = false;

#ifdef _DEBUG 
constexpr bool enableEngineLogger = true;
#else
constexpr bool enableEngineLogger = false;
#endif

#ifdef _MSC_VER
	#define FORCE_INLINE __forceinline
#elif defined(__GNU__) || defined(__clang__)
	#define FORCE_INLINE inline __attribute__((always_inline))
#else 
	#define FORCE_INLINE inline
#endif

// Rough sketch on the module idea 
// if the user wants to use another system or their own 
// they have the possibility to avoid uncessesary bloat 
#define IMPORT_MODULE_HELICON_LOGGER
#define IMPORT_MODULE_HELICON_AI
#define IMPORT_MODULE_HELICON_IN_GAME_OVERLAY_EDITOR
#define IMPORT_MODULE_HELICON_VULKAN_RENDERER
#define IMPORT_MODULE_HELICON_MATH
