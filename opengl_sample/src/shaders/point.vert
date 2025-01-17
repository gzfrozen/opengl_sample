#version 450 core
uniform mat4 model;
in vec4 position;
in vec4 color;
out vec4 vertex_color;
void main()
{
	vertex_color = color;
	gl_Position = model * position;
}