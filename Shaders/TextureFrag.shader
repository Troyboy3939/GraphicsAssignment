#version 450

uniform sampler2D diffuseTexture;

in vec2 v2FinalTexCord;
out vec4 v4FinalColour;

void main()
{
	v4FinalColour = texture(diffuseTexture, v2FinalTexCord);
}