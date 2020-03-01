#version 450


in vec3 v3Normal;

uniform vec4 color = vec4(1,1,1,1);
uniform vec3 v3LightDirection;

out vec4 final_color;

void main()
{
	vec3 v3N = normalize(v3Normal);
	vec3 v3L = normalize(v3LightDirection);

	float fLambertTerm = max(0, min(1, dot(v3N,-v3L)));

	final_color = vec4(fLambertTerm, fLambertTerm, fLambertTerm, 1);
}