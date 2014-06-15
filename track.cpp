#include "track.hpp"
#include "point.hpp"

#include "opengl.hpp"
#include <cmath>

namespace ars {

    Track::Track()
        : color(0.25, 0.25, 0.25) { }

    void Track::render() {
        GLUquadricObj* quadric = gluNewQuadric();

        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, ars::BLACK.getData());
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 2);

        glPushMatrix();
        glTranslatef(0.0, 0.01, 0.0);
        glRotatef(90, 1, 0, 0);

        gluQuadricDrawStyle(quadric, GLU_FILL);
        gluQuadricNormals(quadric, GLU_SMOOTH);
        gluQuadricOrientation(quadric, GLU_INSIDE);

        gluDisk(quadric, 19.0, 24.0, 1024, 10);
        glPopMatrix();

        gluDeleteQuadric(quadric);
    }

    bool Track::isOut(Point point) const {
        double dist = point.x * point.x + point.z * point.z;
        return dist < (19.0 * 19.0) || dist > (24.0 * 24.0);
    }

}
