#include "uniform_buffer.h"

void ubo_create(UniformBuffer* ubo, size_t size, GLuint binding_point) {
	ubo->binding_point = binding_point;
	ubo->size = size;

	glGenBuffers(1, &ubo->id);	
	glBindBuffer(GL_UNIFORM_BUFFER, ubo->id);

	glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);

	glBindBufferBase(GL_UNIFORM_BUFFER, binding_point, ubo->id);
}

void ubo_update(UniformBuffer* ubo, const void* data, size_t size, size_t offset) {
	glBindBuffer(GL_UNIFORM_BUFFER, ubo->id);
	glBufferSubData(GL_UNIFORM_BUFFER, offset, size, data);
}

void ubo_bind_base(const UniformBuffer* ubo) {
	glBindBufferBase(GL_UNIFORM_BUFFER, ubo->binding_point, ubo->id);
}

void ubo_destroy(UniformBuffer* ubo)
{
	if (ubo->id)
	{
		glDeleteBuffers(1, &ubo->id);
		ubo->id = 0;
	}
}