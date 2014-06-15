#ifndef ARS_CAR
#define ARS_CAR

#include "color.hpp"
#include "point.hpp"

namespace ars {

    class Grass;
    class Track;
    class Camera;

    class Car {
        const Grass& grass;
        const Track& track;
        Camera& insideView;

        Point position;
        Color color;

        double speed;
        double angle;
    public:
        Car(const Grass& grass, const Track& track, Camera& insideView);

        void render();

        void update();
        void accelerate();
        void deaccelerate();
        void turnLeft();
        void turnRight();
    };

}

#endif
