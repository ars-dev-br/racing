#include "grass.hpp"
#include "point.hpp"

#include "opengl.hpp"
#include <SOIL/SOIL.h>

#include <iostream>

namespace ars {

    Grass::Grass()
        : color(0.04f, 0.65f, 0.05f) {
    }

    void Grass::initialize() {
        glEnable(GL_TEXTURE_2D);

        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        int width, height;
        unsigned char* image = SOIL_load_image("./assets/grass.png", &width,
                                               &height, 0, SOIL_LOAD_RGB);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0,
                     GL_RGB, GL_UNSIGNED_BYTE, image);
        SOIL_free_image_data(image);

        glDisable(GL_TEXTURE_2D);
    }

    void Grass::render() {
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color.getData());
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture);

        glPushMatrix();
        glScalef(75.0, 1.0, 75.0);

        glBegin(GL_QUADS);
        {
            glNormal3f(0, 1, 0);
            glTexCoord2f(0, 0);
            glVertex3f(-0.5, 0.0, -0.5);

            glNormal3f(0, 1, 0);
            glTexCoord2f(1, 0);
            glVertex3f(0.5, 0.0, -0.5);

            glNormal3f(0, 1, 0);
            glTexCoord2f(1, 1);
            glVertex3f(0.5, 0.0, 0.5);

            glNormal3f(0, 1, 0);
            glTexCoord2f(0, 1);
            glVertex3f(-0.5, 0.0, 0.5);
        }
        glEnd();

        glPopMatrix();

        glDisable(GL_TEXTURE_2D);
    }

    bool Grass::isOut(Point point) const {
        return (point.x > 35.0 || point.x < -35.0)
            || (point.z > 35.0 || point.z < -35.0);
    }

}
