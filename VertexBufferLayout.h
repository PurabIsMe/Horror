
#include <iostream>
#include <vector>
#include <GL/glew.h>
//#include <GL/freeglut.h>

#ifndef VERTEX_BUFFER_LAYOUT
#define VERTEX_BUFFER_LAYOUT 


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
		case GL_FLOAT:
			return 4;
		case GL_UNSIGNED_INT:
			return 4;
		case GL_UNSIGNED_BYTE:
			return 1;
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
		: m_Stride(0) {}

		inline size_t get_vertex_size()
		{
			return m_Stride;
		}

		void Push_float(unsigned int count, bool IsInstance = false)
		{
			m_Elements.push_back({GL_FLOAT, count, GL_FALSE, IsInstance});
			m_Stride += count * VertexBufferElement::GetSizeOFType(GL_FLOAT);
		}

		void Push_uint(unsigned int count, bool IsInstance = false)
		{
			m_Elements.push_back({GL_UNSIGNED_INT, count, GL_FALSE, IsInstance});
			m_Stride += count * VertexBufferElement::GetSizeOFType(GL_UNSIGNED_INT);
		}

		void Push_uchar(unsigned int count, bool IsInstance = false)
		{
			m_Elements.push_back({GL_UNSIGNED_BYTE, count, GL_TRUE, IsInstance});
			m_Stride += count * VertexBufferElement::GetSizeOFType(GL_UNSIGNED_BYTE);
		}

	public:
		inline const std::vector<VertexBufferElement> GetElements() const { return m_Elements; }
		inline unsigned int GetStride() const
		{
			return m_Stride;
		}
};

#endif // !VERTEX_BUFFER_LAYOUT
