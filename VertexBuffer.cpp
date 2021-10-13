#include <VertexBuffer.h>


VertexBuffer::VertexBuffer()
{
}

VertexBuffer::VertexBuffer(const void * data, unsigned int size, GLenum e)
	:m_usage(e)
{
	Gen(data, size, e);
}

void VertexBuffer::Gen(const void * data, unsigned int size, GLenum e)
{
	glGenBuffers(1, &RendererID);
	glBindBuffer(GL_ARRAY_BUFFER, RendererID);

	m_usage = e;
	if (e == GL_STREAM_DRAW)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STREAM_DRAW);
	}
	else if (e == GL_DYNAMIC_DRAW)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
	}
	else if (e == GL_STATIC_DRAW)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	else
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
}

void VertexBuffer::Update(const void * data, unsigned int size)
{
	glBindBuffer(GL_ARRAY_BUFFER, RendererID);

	if (m_usage == GL_STREAM_DRAW)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STREAM_DRAW);
	}
	else if (m_usage == GL_DYNAMIC_DRAW)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
	}
	else if (m_usage == GL_STATIC_DRAW)
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
	else
	{
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &RendererID);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, RendererID);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}