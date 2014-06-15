#ifndef ARS_POINT_HPP
#define ARS_POINT_HPP

namespace ars {

    struct Point {
        double x, y, z, w;

        Point()
            : x(0), y(0), z(0), w(1) { }

        Point(double x, double y, double z)
            : x(x), y(y), z(z), w(1) { }
    };

}

#endif
