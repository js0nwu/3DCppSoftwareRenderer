#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <GL/glut.h>

#include "engine.h"
#include "mesh.h"
#include "thing.h"
#include "camera.h"
#include "transform.h"
#include "putils.h"

using namespace std;

static const int width = 800;
static const int height = 600;

//time keeping
static const int FRAME_CAP = 60;
static const int frame_time = (int) (1000 / FRAME_CAP);

int timef = 0;
int timebase = 0;
int frames = 0;
int time_delta = 0;
int timel = 0;
int timeu = 0;

//engine
engine* thirdpillow;

void render() {
	frames++;
	thirdpillow->render();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glBegin(GL_2D);
	glDrawPixels(width, height, GL_RGB, GL_FLOAT,
			thirdpillow->get_render_buffer());
	glEnd();
	glutSwapBuffers();
}

void update_time() {
	timef = glutGet(GLUT_ELAPSED_TIME);
	time_delta = timef - timel;
	timel = timef;
	if (timef - timebase > 1000) {
		printf("FPS:%4.2f\n", frames * 1000.0 / (timef - timebase));
		timebase = timef;
		frames = 0;
	}
}

void camera_stat() {
	printf("camera: %f %f %f %f %f %f\n",
			transform::get_camera()->get_position()->get_x(),
			transform::get_camera()->get_position()->get_y(),
			transform::get_camera()->get_position()->get_z(),
			transform::get_camera()->get_forward()->get_x(),
			transform::get_camera()->get_forward()->get_y(),
			transform::get_camera()->get_forward()->get_z());
}

void display() {
	update_time();
	timeu += time_delta;
	if (timeu > frame_time) {
		timeu = 0;
		render();
	}
}

void keyboard(unsigned char key, int x, int y) {
	int key_code = (int) key;
	printf("keycode: %d\n", key_code);
	switch (key_code) {
	case 27:
		printf("Exiting...\n");
		thirdpillow->stop();
		exit(0);
		break;
	default:
		break;
	}
	transform::get_camera()->input(key_code);          
	camera_stat();
}

void mouse(int button, int state, int x, int y) {

}

void mouse_motion(int x, int y) {

}

int main(int argc, char** argv) {
	printf("Hello World!\n");
	thirdpillow = new engine(width, height);
	thirdpillow->start();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("test");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouse_motion);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_COLOR_MATERIAL);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0, 0, 0, 0);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glScalef(1, -1, 1);
	glTranslatef(0, -height, 0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutMainLoop();
	return 0;
}
