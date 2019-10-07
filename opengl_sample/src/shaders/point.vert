#version 450 core
in vec4 position;
in vec4 color;
out vec4 vertex_color;
void main()
{
	vertex_color = color;
	gl_Position = position;
}