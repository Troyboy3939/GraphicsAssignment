#version 450

in vec2 v2TexCoord;
in vec3 v3Normal;
in vec3 v3Tangent;
in vec3 v3BiTangent;
in vec4 v4Position;


uniform sampler2D diffuseTexture;
uniform sampler2D specularTexture;
uniform sampler2D normalTexture;

uniform vec3 v3CameraPos;

uniform vec3 v3Ia; //Ambient Light colour
uniform vec3 v3Id; //Diffuse light colour
uniform vec3 v3Is; //Specular light colour


uniform vec3 v3Ka; //Ambient Material colour
uniform vec3 v3Kd; //Diffuse Material colour
uniform vec3 v3Ks; //Specular Material colour
uniform float fSpecularPower; //Material specular Power

uniform vec3 v3LightDirection;



out vec4 v4FragColour;

void main()
{
	vec3 v3N = normalize(v3Normal);
	vec3 v3T = normalize(v3Tangent);
	vec3 v3B = normalize(v3BiTangent);
	vec3 v3L = normalize(v3LightDirection);

	mat3 m3TBN = mat3(v3T,v3B,v3N);

	vec3 v3TexDiffuse = texture(diffuseTexture, v2TexCoord).rgb;
	vec3 v3TexSpecular= texture(specularTexture, v2TexCoord).rgb;
	vec3 v3TexNormal = texture(normalTexture, v2TexCoord).rgb;

	v3N = m3TBN * (v2TexCoord * 2 - 1);

	float fLambertTerm = max(0, min(1, dot(v3N,-v3L)));

	vec3 v3V = normalize(v3CameraPos - v4Position.xyz);
	vec3 v3R = reflect(v3L, v3N);

	float fSpecularTerm = pow(max(0,dot(v3R,v3V)),fSpecularPower);


	vec3 v3Ambient = v3Ia * v3Ka;
	vec3 v3Diffuse = v3Id * v3Kd * fLambertTerm;
	vec3 v3Specular = v3Is * v3Ks * fSpecularTerm;
	
	v4FragColour = vec4(v3Ambient + v3Diffuse + v3Specular, 1);

	//v3FragColour = vec4(v3N, 1);
}