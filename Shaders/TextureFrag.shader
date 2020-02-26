#version 450


in vec2 v2FinalTexCord;
out vec4 v4FinalColour;

uniform sampler2D diffuseTexture;

void main()
{
 v4FinalColour = texture(diffuseTexture, v2FinalTexCord);
}