#ifndef ARS_WORLD
#define ARS_WORLD

#include "camera.hpp"
#include "car.hpp"
#include "grass.hpp"
#include "track.hpp"
#include "walls.hpp"

namespace ars {

    class World {
        Car car;

        Grass grass;
        Track track;
        Walls walls;

        Camera topdown;
        Camera insideCar;
        Camera* current;

    public:
        World();

        void initialize();
        void render();
        void update();
        void handle(unsigned char key);
    };

}

#endif
