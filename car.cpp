#include "car.hpp"

#include "camera.hpp"
#include "grass.hpp"
#include "track.hpp"

#include "opengl.hpp"
#include <cmath>

namespace ars {

    const double degrees = 180.0 / M_PI ;

    Car::Car(const Grass& grass, const Track& track, Camera& insideView)
        : grass(grass), track(track), insideView(insideView),
          position(10, 0, 20), color(0.90, 0.2, 0.2), speed(0) { }

    void Car::render() {
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color.getData());
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color.getData());
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0);

        glPushMatrix();

        glTranslatef(position.x, position.y + 0.5, position.z);
        glRotatef(angle * degrees, 0.0, 1.0, 0.0);

        glPushMatrix();
        glTranslatef(1.0, 0.0, 0.0);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.0, 0.35, 0.0);
        glScalef(1.0, 1.7, 1.0);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-1.0, 0.0, 0.0);
        glutSolidCube(1);
        glPopMatrix();

        glPopMatrix();
    }

    void Car::update() {
        Point velocity(speed * std::cos(angle), 0.0, - speed * std::sin(angle));

        position.x += velocity.x;
        position.z += velocity.z;

        insideView.position = position;
        insideView.position.y = 2.0;

        insideView.center = position;
        insideView.center.x += velocity.x;
        insideView.center.y = 2.0;
        insideView.center.z += velocity.z;

        insideView.up = Point(0, 1, 0);
        insideView.near = 1.55;

        speed *= grass.isOut(position) ? 0 : 1;
        speed *= track.isOut(position) ? 0.9 : 1;
    }

    void Car::accelerate() {
        speed += speed < 0.15 ? 0.006 : 0;
    }

    void Car::deaccelerate() {
        speed -= speed > 0.01 ? 0.006 : 0;
    }

    void Car::turnLeft() {
        angle += 0.06;
    }

    void Car::turnRight() {
        angle -= 0.06;
    }

}
