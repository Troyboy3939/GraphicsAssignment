#version 450

layout (location = 0) in vec4 v4LocalPosition;
layout(location = 1) in vec2 v2TextureCoordinates;
layout(location = 2) in vec4 v4Normal;
layout(location = 3) in vec4 v4Tangent;

uniform mat4 m4PVM;
uniform mat4 m4ModelMatrix;
uniform mat3 m3NormalMatrix;

out vec2 v2FinalTexCord;
out vec3 v3Normal;
out vec3 v3Tangent;
out vec3 v3BiTangent;
out vec4 v4Position;


void main()
{
	v2FinalTexCord = v2TextureCoordinates;  
	v3Position = m4ModelMatrix * v4LocalPosition;
	v3Normal = m3NormalMatrix * v3Normal.xyz;
	v3Tangent = NormalMatrix * v4Tangent.xyz;
	v3BiTangent = cross(v3Normal, v3Tangent);
	gl_Position = (m4PVM * m4ModelMatrix) * v4LocalPosition;
}