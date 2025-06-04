#version 410 core

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 outVertexColor;
uniform vec3 ourColor;
uniform bool useUniform;
void main()
{
    float offset = float(gl_InstanceID) * 0.1;
    gl_Position =  vec4(aVertexPosition.x+offset,aVertexPosition.y,aVertexPosition.z, 1.0);
    
    if(useUniform==true)
    {
         outVertexColor=ourColor;
    }
   else
   {
    outVertexColor=aVertexColor;
   }
}
