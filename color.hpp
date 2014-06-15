#ifndef ARS_COLOR_HPP
#define ARS_COLOR_HPP

namespace ars {

    class Color {
    public:
        float r, g, b, a;


        Color();
        Color(float r, float g, float b);

        const float* getData() const;
        static Color random();
    };

    const Color BLACK(0.0f, 0.0f, 0.0f);
    const Color WHITE(1.0f, 1.0f, 1.0f);

    const Color RED(1.0f, 0.0f, 0.0f);
    const Color GREEN(0.0f, 1.0f, 0.0f);
    const Color BLUE(0.0f, 0.0f, 1.0f);

    const Color YELLOW(1.0f, 1.0f, 0.0f);
    const Color MAGENTA(1.0f, 0.0f, 1.0f);
    const Color CYAN(0.0f, 1.0f, 1.0f);
}

#endif
