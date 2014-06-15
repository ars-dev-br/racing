#ifndef ARS_WALLS
#define ARS_WALLS

#include "color.hpp"

namespace ars {

    class Walls {
        Color color;

    public:
        Walls();

        void render();
    };

}

#endif
