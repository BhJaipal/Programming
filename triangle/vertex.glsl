#version 330 core
in vec3 vertex;
in vec3 color;
uniform mat4 MVP;
out vec3 fragColor;

void main(){
  gl_Position = MVP * vec4(vertex, 1);
  fragColor = color;
}
