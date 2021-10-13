#pragma once

#include "GL/glew.h"

class IndexBuffer
{
private:
	unsigned int m_RendererID;

	unsigned int Count;
public:
	IndexBuffer();
	IndexBuffer(const unsigned int* data, unsigned int count);
	~IndexBuffer();

	void Gen(const unsigned int* data, unsigned int count);
	void Update(const unsigned int* data, unsigned int count);
	void Bind() const;
	void Unbind() const;
	inline unsigned int GetCount() const {
		return Count;
	}
};