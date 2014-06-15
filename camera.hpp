#ifndef ARS_CAMERA_HPP
#define ARS_CAMERA_HPP

#include "point.hpp"

namespace ars {

    class Camera {
    public:
        Point position;
        Point center;
        Point up;

        double fov, aspect, near, far;

        Camera();

        /**
         * Sets OpenGL camera using these values.
         */
        void setCamera();
    };

}

#endif
