#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "shader.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

GLuint shaderProgramID;
GLuint vao;
GLuint vbo;
GLuint positionID, colorID;

GLfloat vertices[] = {
	0.75f, 0.0f, 0.0f,  //right
	0.0f, 0.75f, 0.0f,  //top
	-0.75f, 0.0f, 0.0f, //left
	0.0f, -0.75f, 0.0f, //bottom
};

GLfloat colors[] = {
	1.0f, 1.0f, 1.0f, 1.0f,  //right
	1.0f, 0.0f, 0.0f, 1.0f, //top
	1.0f, 1.0f, 1.0f, 1.0f, //left
	0.0f, 0.0f, 1.0f, 1.0f, //bottom
};



void render(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawArrays(GL_POLYGON, 0, 4);
	glutSwapBuffers();
}

int main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(800,600);
	glutCreateWindow("Alex Kelly Lab2");
	glutDisplayFunc(render);
	glewInit();

	shaderProgramID = createShaders();


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	// Create the buffer, but don't load anything yet
	glBufferData(GL_ARRAY_BUFFER, sizeof(colors)*sizeof(vertices), NULL, GL_STATIC_DRAW);
	// Load the vertex points
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); 
	// Load the colors right after that
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices),sizeof(colors), colors);
	
	// Find the position of the variables in the shader
	positionID = glGetAttribLocation(shaderProgramID, "s_vPosition");
	colorID = glGetAttribLocation(shaderProgramID, "s_vColor");

	glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(3*4*sizeof(GLfloat)));
	glUseProgram(shaderProgramID);
	glEnableVertexAttribArray(positionID);
	glEnableVertexAttribArray(colorID);
	
	glutMainLoop();


	glutMainLoop();

	return 0;

}
