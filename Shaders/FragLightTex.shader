#version 450

in vec2 v2OutTexCoord;
in vec3 v3OutNormal;
in vec3 v3OutTangent;
in vec3 v3OutBiTangent;
in vec4 v4OutPosition;


uniform sampler2D diffuseTexture;
//uniform sampler2D specularTexture;
uniform sampler2D normalTexture;

uniform vec3 v3CameraPos;


struct Light
{
	vec3 v3Id; //Diffuse light colour
	vec3 v3Is; //Specular light colour
	vec3 v3LightDirection;
};

uniform vec3 v3Ia; //Ambient Light colour

const int nNoLights = 2;
uniform Light aLights[nNoLights];




uniform vec3 v3Ka; //Ambient Material colour
uniform vec3 v3Kd; //Diffuse Material colour
uniform vec3 v3Ks; //Specular Material colour
uniform float fSpecularPower; //Material specular Power




 out vec4 v4FragColour;

void main()
{
	vec3 v3N = normalize(v3OutNormal);
	vec3 v3T = normalize(v3OutTangent);
	vec3 v3B = normalize(v3OutBiTangent);

	mat3 m3TBN = mat3(v3T,v3B,v3N);

	vec3 v3TexDiffuse = texture(diffuseTexture, v2OutTexCoord).rgb;
	//vec3 v3TexSpecular= texture(specularTexture, v2OutTexCoord).rgb;
	vec3 v3TexNormal = texture(normalTexture, v2OutTexCoord).rgb;

	v3N = m3TBN * (v3TexNormal* 2 -
 1);

	vec3 v3V = normalize(v3CameraPos - v4OutPosition.xyz);


	vec3 v3Ambient = v3Ia * v3Ka;
	for (int i = 0; i < nNoLights; i++)
	{

		vec3 v3L = normalize(aLights[i].v3LightDirection);
		vec3 v3R = reflect(v3L, v3N);
		float fSpecularTerm = pow(max(0,dot(v3R,v3V)),fSpecularPower);

		float fLambertTerm = max(0, min(1, dot(v3N,-v3L)));

		vec3 v3Diffuse = aLights[i].v3Id * v3Kd * v3TexDiffuse *  fLambertTerm;
		vec3 v3Specular = aLights[i].v3Is * v3Ks * fSpecularTerm;
	
		v4FragColour += vec4(v3Ambient + v3Diffuse + v3Specular, 1);
		//v4FragColour = vec4(aLights[1].v3Is,1);
	}

}