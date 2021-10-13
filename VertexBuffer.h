
#include <GL/glew.h>
//#include <GL/freeglut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>

#ifndef VERTEX_BUFFER
#define VERTEX_BUFFER

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

#endif // !VERTEX_BUFFER

