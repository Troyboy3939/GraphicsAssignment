#version 450

layout(location = 0) in vec4 v4LocalPosition;
layout(location = 1) in vec4 v4Normal;


out vec3 v3Normal;

uniform mat4 m4PVM;
uniform mat4 m4ModelMatrix;
uniform mat3 m3NormalMatrix;

void main()
{
	v3Normal = m3NormalMatrix * v3Normal.xyz;
	gl_Position = (m4PVM * m4ModelMatrix) * v4LocalPosition;
}