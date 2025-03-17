#version 410 core

layout(location = 0) in vec3 vColor;
layout(location = 1) in vec2 fVertexTextureCordinate;

layout(location = 0) out vec4 fFragClr;

uniform sampler2D     uTex2d;
uniform sampler2D     uTex2d1;
void main()
{
    vec4 color_1 = texture(uTex2d,fVertexTextureCordinate);
    vec4 color_2 = texture(uTex2d1,fVertexTextureCordinate);
    fFragClr = color_2*color_1;
}
