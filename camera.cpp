#include "camera.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#elif WIN32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#elif __linux__
#include <GL/gl.h>
#include <GL/glut.h>
#endif

namespace ars {

    Camera::Camera()
        : fov(45), aspect(1), near(0.1), far(10000) { }

    void Camera::setCamera() {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(fov, aspect, near, far);

        gluLookAt(position.x, position.y, position.z,
                  center.x, center.y, center.z,
                  up.x, up.y, up.z);

        glMatrixMode(GL_MODELVIEW);
    }

}
