#version 430

attribute vec3 position;
attribute vec2 texCoord;
attribute vec3 normal;

uniform mat4 MVPtransform;

varying vec3 normal0;
varying vec2 texCoord0;

void main()
{
	gl_Position = MVPtransform * vec4(position, 1.0);
	normal0 = (MVPtransform * vec4(normal,0.0)).xyz;
	texCoord0 = texCoord;
}