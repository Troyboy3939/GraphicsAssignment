#version 450

layout (location = 0) in vec3 v3LocalPosition;
layout(location = 1) in vec2 v2TextureCoordinates;

uniform mat4 m4PVM;
uniform mat4 m4ModelMatrix;

out vec2 v2FinalTexCord;

void main()
{
	v2FinalTexCord = v2TextureCoordinates;
	gl_Position = (m4PVM * m4ModelMatrix) * vec4(v3LocalPosition,1);
}