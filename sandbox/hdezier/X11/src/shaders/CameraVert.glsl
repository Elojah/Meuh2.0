in vec3 vpm;
uniform mat4 mvp;

void main(){
	vec4 v = vec4(vpm,1);
	gl_Position = mvp * v;
}
