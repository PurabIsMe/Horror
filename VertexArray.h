
#include "VertexBuffer.h"
#include "GL/glew.h"
//#include <GL/freeglut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>

#ifndef VERTEX_ARRAY
#define VERTEX_ARRAY

class VertexBufferLayout;

class VertexArray
{
private:
	unsigned int RendererID;
	unsigned int LastAttrib;
public:
	VertexArray();
	~VertexArray();

	void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
	void Bind() const;
	void Unbind() const;

};

#endif // !VERTEX_ARRAY