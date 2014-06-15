#include "color.hpp"

#include <random>

static std::random_device rd;
static std::mt19937 gen(rd());
static std::uniform_real_distribution<double> dist;

namespace ars {

    Color::Color()
        : r(0), g(0), b(0), a(1) { }

    Color::Color(float r, float g, float b)
        : r(r), g(g), b(b), a(1) { }

    const float* Color::getData() const {
        return reinterpret_cast<const float*>(this);
    }

    Color Color::random() {
        return Color(dist(gen), dist(gen), dist(gen));
    }
}
