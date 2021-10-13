#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Mesh{
    VertexArray va;
    VertexBuffer vb;
    IndexBuffer ib;

    void Bind(){
        va.BInd();
        vb.Bind();
        ib.Bind();
    }
};