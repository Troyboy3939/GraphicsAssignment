#version 450


in vec2 v2FinalTexCord;
in vec3 v3Normal;
in vec4 v4Position;

out vec4 v4FinalColour;


uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;

uniform vec3 v3Ka;
uniform vec3 v3Ks;
uniform vec3 v3Kd;
uniform float fSpecularPower;


uniform vec3 v3Ia;
uniform vec3 v3Id;
uniform vec3 v3Is;
uniform vec3 v3LightDirection;

uniform vec3 v3CameraPosition;


void main()
{
	vec3 v3N = normalize(v3Normal);
	vec3 v3L = normalize(v3LightDirection);

	vec3 v3TexDiffuse = texture(diffuseTexture, v2FinalTexCord);
	vec3 v3TexSpecular = texture(specularTexture, v2FinalTexCord);

	float fLambertTerm = max(0, min(1, dot(v3N,-v3L)));

	vec3 v3V = normalize(v3CameraPosition - v4Position.xyz);
	vec3 v3R = reflect(v3L, v3N);

	float fSpecularTerm = pow(max(0,dot(v3R,v3V)),fSpecularPower);

	vec3 v3Ambient = v3Ia * v3Kd;
	vec3 v3Diffuse = v3Id * v3Kd * v3TexDiffuse * fLambertTerm;
	vec3 v3Specular = v3Is * v3Ks * v3TexSpecular * fSpecularTerm;


	v4FinalColour = vec4(v3Ambient + v3Diffuse + v3Specular,1);
	//v4FinalColour = texture(diffuseTexture, v2FinalTexCord);
}