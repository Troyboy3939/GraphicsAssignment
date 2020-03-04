#version 450

layout(location = 0) in vec4 v4LocalPosition;
layout(location = 1) in vec4 v4Normal;


out vec3 v3Normal;
out vec4 v4Position;

uniform mat4 m4PV;
uniform mat4 m4ModelMatrix;
uniform mat3 m3NormalMatrix;

void main()
{
	v4Position = m4ModelMatrix * v4LocalPosition;
	v3Normal = (m4ModelMatrix * vec4(v4Normal.xyz, 0)).xyz;
	gl_Position = (m4PV * m4ModelMatrix) * v4LocalPosition;
}