#version 330 core
precision mediump float;
in float zDist;
out vec4 FragColor;

void main() {
	float brightness = clamp(zDist / 6.0 + 0.5, 0.0, 1.0);
	FragColor = vec4(vec3(brightness), 1);
}
