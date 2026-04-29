#pragma once 

#include <glad/glad.h>
#include "engine_assert.h"
#include "vec3.h"


struct GlobalUBOData
{
    // glm::mat4 view;
    // glm::mat4 projection;

    vec4 camera_position;
    float delta_time;

    float time;
    float padding[3]; // std140 alignment safety
};

struct UniformBuffer {
	GLuint id;
	GLuint binding_point;
	size_t size;
};

void ubo_create(UniformBuffer* ubo, size_t size, GLuint binding_point);
void ubo_update(UniformBuffer* ubo, const void* data, size_t size, size_t offset = 0);
void ubo_bind_base(const UniformBuffer* ubo);
void ubo_destroy(UniformBuffer* ubo);
