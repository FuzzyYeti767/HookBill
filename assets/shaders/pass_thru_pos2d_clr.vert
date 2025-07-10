#version 410 core

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;
layout(location = 2) in vec2 aTextureCordinate;
out vec3 outVertexColor;
out vec2 outTextureCordinate;
uniform vec3 ourColor;
uniform bool useUniform;
void main()
{
   
    gl_Position =  vec4(aVertexPosition.x,aVertexPosition.y,aVertexPosition.z, 1.0);
         
    outVertexColor=aVertexColor;
    outTextureCordinate=aTextureCordinate;
   
}
