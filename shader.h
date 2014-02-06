#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>


const char* vertexShader(
	"#version 130\n"
	"in vec4 s_vPosition;\n"
	"in vec4 s_vColor;\n"
	"out vec4 color;\n"
	"void main () {\n"
	"	color = s_vColor;\n"
	"	gl_Position = s_vPosition;\n"
	"}\n"
);

const char* fragmentShader(
	"#version 130\n"
	"in vec4 color;\n"
	"out vec4 fColor;\n"

	"void main () {\n"
	"	fColor = color;\n"
	"}\n"
);

int createShaders(){

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderID, 1, (const GLchar**) &vertexShader, NULL);
	glCompileShader(vertexShaderID);

	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderID, 1, (const GLchar**) &fragmentShader, NULL);
	glCompileShader(fragmentShaderID);	

	GLuint shaderID = glCreateProgram();
	glAttachShader(shaderID, vertexShaderID);
	glAttachShader(shaderID, fragmentShaderID);
	glLinkProgram(shaderID);

	return shaderID;
}

bool compiledStatus(GLint shaderID){
	
}
