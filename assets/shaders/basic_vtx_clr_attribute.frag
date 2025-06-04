#version 410 core

out vec4 fFragColor;
in vec3 outVertexColor;
void main()
{
    fFragColor = vec4(outVertexColor, 0.0); 
}
