#include "world.hpp"

#include "opengl.hpp"

const int WINDOW_WIDTH = 650;
const int WINDOW_HEIGHT = 650;

ars::World world;

static void display();
static void idle();
static void keyboard(unsigned char key, int x, int y);
static void reshape(int width, int height);

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Andre Ramaciotti - N4");

    world.initialize();

    glutDisplayFunc(&display);
    glutIdleFunc(&idle);
    glutKeyboardFunc(&keyboard);
    glutReshapeFunc(&reshape);

    glutMainLoop();
    return 0;
}

static void display() {
    world.render();

    glFlush();
    glutSwapBuffers();
}

static void idle() {
    world.update();
    glutPostRedisplay();
}

static void keyboard(unsigned char key, int x, int y) {
    world.handle(key);
    glutPostRedisplay();
}

static void reshape(int width, int height) {
    glutPostRedisplay();
}
