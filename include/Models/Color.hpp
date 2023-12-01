#pragma once

#include "rapidjson-macros/shared/macros.hpp"
#include "config-utils/shared/config-utils.hpp"

namespace ColourSwitcher::Models
{
    DECLARE_JSON_CLASS(Color,
        VALUE_DEFAULT(float, r, 0);
        VALUE_DEFAULT(float, g, 0);
        VALUE_DEFAULT(float, b, 0);
        VALUE_DEFAULT(float, a, 0);

        CONVERSION(Color,
            r = round(other.r);
            g = round(other.g);
            b = round(other.b);
            a = round(other.a);
            ,
            (r, g, b, a)
        )

        Color() = default;
        Color(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) {}
    )
}