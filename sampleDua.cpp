#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLfloat spin = 0.0;

void init(void){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
		glRotatef(spin, 0.0,0.0,1.0);
		glColor3f(0.4,0.9,0.6);
		glRectf(-25.0,-25.0,25.0,25.0);

	glPopMatrix();
	glutSwapBuffers();
}

void spinDisplay(){
	spin = spin +2.0;
	if(spin > 360.0 ){
		spin= spin -3600;
	}
	glutPostRedisplay();
}

void reshape(int w , int h){
	glViewport(0, 0, (GLsizei) w , (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y){
	switch(button){
	case GLUT_LEFT_BUTTON :
			if(state == GLUT_DOWN)
				glutIdleFunc(spinDisplay);
			break;
	case GLUT_RIGHT_BUTTON:
			if(state == GLUT_DOWN)
				glutIdleFunc(NULL);
			break;
	default : break;
	}
}

int main (int argc, char** argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(250,250);
glutInitWindowPosition(100,100);
glutCreateWindow("try");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMouseFunc(mouse);
glutMainLoop();
return 0;
}
