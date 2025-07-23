#version 410 core

out vec4 fFragColor;

in vec3 outVertexColor;
in vec2  outTextureCordinate;
uniform sampler2D Utex2d;
uniform sampler2D Utex2d1;
void main()
{
    vec4 color1 = texture(Utex2d, outTextureCordinate);
    vec4 color2 = texture(Utex2d1, outTextureCordinate);
    fFragColor=color2;
}
