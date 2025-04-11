#pragma once
#include "IMesh.h"
#include <vector>
#include<GLVertexBuffer.h>
#include<GLVertexArray.h>


class CubeMesh : public IMesh {
public:
    CubeMesh();              
    ~CubeMesh();

    CubeMesh(const CubeMesh&) = delete;
    CubeMesh& operator=(const CubeMesh&) = delete;
    CubeMesh(CubeMesh&&) noexcept;
    CubeMesh& operator=(CubeMesh&&) noexcept;

    void Use(bool value);
    void Draw() const override;

private:
    GLVertexArray vao;            
   
   

  
};
