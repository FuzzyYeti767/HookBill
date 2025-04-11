#include"CubeMesh.h"
#include "CubeMesh.h"
#include <glad/glad.h>
#include<vec3.h>
CubeMesh::CubeMesh()
{
   
    std::vector<vec3> vertices = 
    {
        // x, y, z
        vec3{ -0.5f, -0.5f, -0.5f},
        vec3{ 0.5f,  -0.5f, -0.5f},
        vec3{ 0.5f,   0.5f, -0.5f},
        vec3{ -0.5f,  0.5f, -0.5f},
        vec3{ -0.5f, -0.5f,  0.5f},
        vec3{ 0.5f,  -0.5f,  0.5f},
        vec3{ 0.5f,   0.5f,  0.5f},
        vec3{ -0.5f,  0.5f,  0.5f }
    };

   
    std::vector<unsigned int> indices = {
        0, 1, 2, 2, 3, 0, // back
        4, 5, 6, 6, 7, 4, // front
        4, 5, 1, 1, 0, 4, // bottom
        6, 7, 3, 3, 2, 6, // top
        5, 6, 2, 2, 1, 5, // right
        7, 4, 0, 0, 3, 7  // left
    };


    GLIndexBuffer index(indices);

    GLAttributeLayout position;
    position.component_dimension = GLAttributeLayout::_3;
    position.component_type = GLAttributeLayout::Float;
    position.normalized = false;
    position.offset = 0;
    position.relative_offset = 0;
    position.stride = sizeof(vec3);
    position.vertex_layout_location = 0;
    vao.SetIndexBuffer(std::move(index));
    vao.SetPrimitivePattern(GLPrimitive::Triangles);
	vao.AddVertexBuffer(GLVertexBuffer(std::span{ vertices }), { position });


  
}

CubeMesh::~CubeMesh() {
  
}

CubeMesh::CubeMesh(CubeMesh&& other) noexcept 
{
	// Move constructor implementation
	vao = std::move(other.vao);

}

CubeMesh& CubeMesh::operator=(CubeMesh&& other) noexcept
{
	// Move assignment operator implementation  
	if (this != &other) {
		vao = std::move(other.vao);
	}
   
	return *this;
    
}
void CubeMesh::Use(bool value)
{
    vao.Use(value);
}


void CubeMesh::Draw() const
{
    GLDrawIndexed(vao);
}
   
