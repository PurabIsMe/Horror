#pragma once

#include <iostream>
#include <vector>
#include <GL/glew.h>


struct VertexBufferElement 
{
	unsigned int type;
	unsigned int count;
	unsigned char normalized;
	bool Instanced = false;

	static unsigned int GetSizeOFType(unsigned int type)
	{
		switch (type) 
		{
			case GL_FLOAT:			return 4;
			case GL_UNSIGNED_INT:	return 4;
			case GL_UNSIGNED_BYTE:	return 1;
		}
		std::cout << "Wrong type!" << std::endl;
		return 0;
	}
};

class VertexBufferLayout 
{
private:
	std::vector<VertexBufferElement> m_Elements;
	unsigned int m_Stride;
public: 
	VertexBufferLayout()
		:m_Stride(0) {}

	template<typename T>
	void Push(unsigned int count, bool IsInstance = false)
	{
		static_assert(false);
	}

private:

	template<>
	void Push<float>(unsigned int count, bool IsInstance)
	{
		m_Elements.push_back({ GL_FLOAT, count, GL_FALSE,IsInstance });
		m_Stride += count * VertexBufferElement::GetSizeOFType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count, bool IsInstance)
	{
		m_Elements.push_back({ GL_UNSIGNED_INT,count, GL_FALSE,IsInstance });
		m_Stride += count * VertexBufferElement::GetSizeOFType(GL_UNSIGNED_INT);
	}
	
	template<>
	void Push<unsigned char>(unsigned int count, bool IsInstance)
	{
		m_Elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE,IsInstance });
		m_Stride += count * VertexBufferElement::GetSizeOFType(GL_UNSIGNED_BYTE);
	}

	inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
	inline unsigned int GetStride() const
	{
		return m_Stride;
	}
};