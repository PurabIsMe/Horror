#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "glm/glm.hpp"

#include <vector>

struct RenderMesh{
    VertexArray va;
    VertexBuffer vb;
    IndexBuffer ib;
    VertexBufferLayout layout;

    void Initialize2D(){
        //2 floats = Position (x, y)
        layout.Push_float(2);
        //4 floats = Color (r, g, b, a)
        layout.Push_float(4);
        //2 floats = Texture Coordinates (x, y)
        layout.Push_float(2);
    }

    void SetData(void* vert_data, size_t vertex_count, void* tri_data, size_t triangle_count){
        Bind();
        vb.Gen(vert_data, vertex_count * layout.get_vertex_size());
        ib.Gen((unsigned int*)tri_data, triangle_count * 3);
        va.AddBuffer(vb, layout);
    }

    void UpdateData(void* vert_data, size_t vertex_count, void* tri_data, size_t triangle_count){
        Bind();
        vb.Update(vert_data, vertex_count * layout.get_vertex_size());
        ib.Update((unsigned int*)tri_data, triangle_count * 3);
    }

    void Bind(){
        va.Bind();
        vb.Bind();
        ib.Bind();
    }

    void UnBind(){
        va.Unbind();
        vb.Unbind();
        ib.Unbind();
    }
};

struct Ver2D{
    glm::vec2 pos;
    glm::vec4 color;
    glm::vec2 uv; //texture coordinates.

    Ver2D(glm::vec2 pos, glm::vec4 color = glm::vec4(1,1,1,1), glm::vec2 uv = glm::vec2(0,0))
    :pos(pos), color(color), uv(uv){

    }

};

struct Tri{
    unsigned int a, b, c;
    Tri(unsigned int a, unsigned int b, unsigned int c) : a(a), b(b), c(c){

    }
};

template<typename vertex>
class Mesh{
    private:
        std::vector<vertex> vertices;
        std::vector<Tri> triangles;

    public:
        Mesh(){

        }

        void GenRect(float width, float height){
            vertex a(glm::vec2(-width/2, height/2));
            vertex b(glm::vec2(width/2, height/2));
            vertex c(glm::vec2(width/2, -height/2));
            vertex d(glm::vec2(-width/2, -height/2));

            vertices.push_back(a);
            vertices.push_back(b);
            vertices.push_back(c);
            vertices.push_back(d);

            triangles.push_back(Tri(0, 1, 2));
            triangles.push_back(Tri(0, 2, 3));
        }

        inline void* get_vertex_data(){
            return vertices.data();
        }

        inline size_t get_vertex_count(){
            return vertices.size();
        }

        inline void* get_triangle_data(){
            return triangles.data();
        }

        inline size_t get_triangle_count(){
            return triangles.size();
        }
};
