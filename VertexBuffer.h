
#pragma once
#include <GL/glew.h>

class VertexBuffer
{
public:
	VertexBuffer();
	void Gen(const void* data, unsigned int size, GLenum e = GL_STATIC_DRAW);
	VertexBuffer(const void* data, unsigned int size, GLenum e = GL_STATIC_DRAW);
	void Update(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;

private:
	unsigned int RendererID;
	GLenum m_usage;
};