#include "world.hpp"

#include "color.hpp"

#include "opengl.hpp"
#include <string>
#include <cmath>

namespace ars {

    const ars::Color AMBIENT_COLOR(0.25f, 0.25f, 0.125f);
    const ars::Color SPOTLIGHT_COLOR(0.4f, 0.4f, 0.2f);

    World::World()
        : car(grass, track, insideCar), current(&topdown) { }

    void World::initialize() {
        glClearColor(0.0f, 0.05f, 0.12f, 1.0f);
        glEnable(GL_DEPTH_TEST);

        topdown.position = ars::Point(-2.5, 60.0, 80.0);
        topdown.center = ars::Point(0.0, 2.0, 0.0);
        topdown.up = ars::Point(0.0, 1.0, 0.0);

        glEnable(GL_LIGHTING);

        glLightfv(GL_LIGHT0, GL_DIFFUSE, AMBIENT_COLOR.getData());
        glLightfv(GL_LIGHT0, GL_SPECULAR, AMBIENT_COLOR.getData());
        glEnable(GL_LIGHT0);

        for (GLenum i = GL_LIGHT1; i < GL_LIGHT1 + 7; i++) {
            GLfloat direction[] = { 0, -1, 0, 1 };

            GLfloat position[] = { 0, 5, 0, 1 };
            position[0] = 21 * std::sin(i * (2 * M_PI) / 7.0);
            position[2] = 21 * std::cos(i * (2 * (M_PI) / 7.0));

            glLightfv(i, GL_AMBIENT, ars::BLACK.getData());
            glLightfv(i, GL_DIFFUSE, SPOTLIGHT_COLOR.getData());
            glLightfv(i, GL_SPECULAR, SPOTLIGHT_COLOR.getData());
            glLightfv(i, GL_POSITION, position);
            glLightfv(i, GL_SPOT_DIRECTION, direction);
            glLightf(i, GL_SPOT_CUTOFF, 62.0);
            glLightf(1, GL_SPOT_EXPONENT, 15);

            glEnable(i);
        }

        grass.initialize();
    }

    void World::render() {
        current->setCamera();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        grass.render();
        track.render();
        walls.render();
        car.render();
    }

    void World::update() {
        car.update();
    }

    void World::handle(unsigned char key) {
        key = std::tolower(key);

        switch(key) {
        case '1':
            current = &topdown;
            break;
        case '2':
            current = &insideCar;
            break;
        case 'w':
            car.accelerate();
            break;
        case 's':
            car.deaccelerate();
            break;
        case 'a':
            car.turnLeft();
            break;
        case 'd':
            car.turnRight();
            break;
        }
    }

}
