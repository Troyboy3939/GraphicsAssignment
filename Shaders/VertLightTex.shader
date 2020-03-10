#version 450

layout(location = 0) in vec4 v4LocalPosition;
layout(location = 1) in vec4 v4Normal;
layout(location = 2) in vec2 v2TexCoord;
layout(location = 3) in vec4 v4Tangent;

out vec2 v2OutTexCoord;
out vec3 v3OutNormal;
out vec3 v3OutTangent;
out vec3 v3OutBiTangent;
out vec4 v4OutPosition;

uniform mat4 m4PV;
uniform mat4 m4ModelMatrix;
uniform mat3 m3NormalMatrix;

void main()
{
	v2TexCoord = v2TexCoord;
	v4OutPosition = m4ModelMatrix * v4LocalPosition;
	v3OutNormal = (m4ModelMatrix * vec4(v4Normal.xyz, 0)).xyz;
	v3OutTangent = m3NormalMatrix * v4Tangent.xyz;
	v3OutBiTangent = cross(v3OutNormal, v3OutTangent) * v4Tangent.w;
	gl_Position = (m4PV * m4ModelMatrix) * v4LocalPosition;
}