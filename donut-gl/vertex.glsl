#version 330 core
layout(location = 0) in vec3 vertex;
uniform mat4 MVP;
out float zDist;

void main(){
  gl_Position = MVP * vec4(vertex, 1);
  zDist = vertex.z;
}
