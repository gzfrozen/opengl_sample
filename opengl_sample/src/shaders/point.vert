#version 450 core
uniform vec2 size;
uniform float scale;
in vec4 position;
in vec4 color;
out vec4 vertex_color;
void main()
{
	vertex_color = color;
	gl_Position = vec4(2.0 * position.xy * scale / size, position.zw);
}