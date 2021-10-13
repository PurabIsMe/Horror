#include <GL/glew.h>
#include <GL/freeglut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>

#ifndef INDEX_BUFFER
#define INDEX_BUFFER

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

#endif // !INDEX_BUFFER
