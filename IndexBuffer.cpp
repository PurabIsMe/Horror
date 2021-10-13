
#include <IndexBuffer.h>

IndexBuffer::IndexBuffer()
{
}

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
{
	Gen(data, count);
}

IndexBuffer::~IndexBuffer()
{
	(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Gen(const unsigned int * data, unsigned int count)
{
	glGenBuffers(1, &m_RendererID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);

	Count = count;
}

void IndexBuffer::Update(const unsigned int * data, unsigned int count)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
	Count = count;
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}