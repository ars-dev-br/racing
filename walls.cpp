#include "walls.hpp"

#include "opengl.hpp"

namespace ars {

    Walls::Walls()
        : color(0.78, 0.76, 0.75) { }

    void Walls::render() {
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color.getData());
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0);

        glPushMatrix();
        glTranslatef(0.0, 0.0, 37.5);
        glScalef(75.0, 3.0, 1.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0, 0.0, -37.5);
        glScalef(75.0, 3.0, 1.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(37.5, 0.0, 0.0);
        glScalef(1.0, 3.0, 75.0);
        glutSolidCube(1.0);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-37.5, 0.0, 0.0);
        glScalef(1.0, 3.0, 75.0);
        glutSolidCube(1.0);
        glPopMatrix();
    }

}
