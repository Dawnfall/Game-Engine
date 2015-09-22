#version 430

varying vec3 normal0;
varying vec2 texCoord0;

uniform sampler2D gSampler;

void main()
{
	gl_FragColor = texture2D(gSampler, texCoord0)
		* clamp(dot(-vec3(0,0,1), normal0),0.0,1.0);
}