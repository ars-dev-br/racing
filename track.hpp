#ifndef ARS_TRACK
#define ARS_TRACK

#include "color.hpp"

namespace ars {

    class Point;

    class Track {
        Color color;
    public:
        Track();

        void render();
        bool isOut(Point point) const;
    };

}

#endif
