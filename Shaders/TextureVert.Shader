#version 450

layout (location = 0) in vec4 v4LocalPosition;
layout(location = 1) in vec4 v4Normal;
layout(location = 2) in vec2 v2TextureCoordinates;
layout(location = 3) in vec4 v4Tangent;

uniform mat4 m4PVM;
uniform mat4 m4ModelMatrix;

out vec2 v2FinalTexCord;


void main()
{
	v2FinalTexCord = v2TextureCoordinates;  
	gl_Position = (m4PVM * m4ModelMatrix) * v4LocalPosition;
}