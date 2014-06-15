#ifndef ARS_GRASS
#define ARS_GRASS

#include "color.hpp"

namespace ars {

    class Point;

    class Grass {
        Color color;
        unsigned int texture;

    public:
        Grass();

        void initialize();
        void render();
        bool isOut(Point point) const;
    };

}

#endif
