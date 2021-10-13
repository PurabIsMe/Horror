#include "VertexArray.h"
#include "VertexBufferLayout.h"


VertexArray::VertexArray()
	:LastAttrib(0)
{
	glGenVertexArrays(1, &RendererID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &RendererID);
}

void VertexArray::AddBuffer(const VertexBuffer & vb, const VertexBufferLayout & layout)
{
	Bind();
	vb.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++) 
	{
		const auto& element = elements[i];
		if (!element.Instanced)
		{
			glEnableVertexArrayAttrib(RendererID, i + LastAttrib);
		}
		else
		{
			glEnableVertexAttribArray(i + LastAttrib);
		}

		glVertexAttribPointer(i + LastAttrib, element.count, element.type, element.normalized, layout.GetStride(), (const void*) offset);
		offset += element.count * VertexBufferElement::GetSizeOFType(element.type);

		if (element.Instanced)
		{
			glVertexAttribDivisor(i + LastAttrib, 1);
		}
	}
	LastAttrib += elements.size();
}

void VertexArray::Bind() const
{
	glBindVertexArray(RendererID); 
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}