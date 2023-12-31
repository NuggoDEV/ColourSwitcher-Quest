#pragma once

#include "rapidjson-macros/shared/macros.hpp"
#include "Models/Color.hpp"

namespace ColourSwitcher::Models
{
    DECLARE_JSON_CLASS(TimedSwitch, 
        VALUE_DEFAULT(bool, IsActive, false);
        VALUE_DEFAULT(int, ActivationTime, 0);
        VALUE_DEFAULT(Color, LeftSaber, Color(1, 0, 0, 1));
        VALUE_DEFAULT(Color, RightSaber, Color(0, 1, 0, 1));
        VALUE_DEFAULT(Color, Obstacle, Color(0.25f, 0.25f, 0.25f, 1));
        VALUE_DEFAULT(Color, Bomb, Color(1, 1, 1, 1));

        TimedSwitch() = default;
        TimedSwitch(bool _isActive, int _activationTime, Color _leftSaber, Color _rightSaber, Color _obstacle, Color _bomb) : 
            IsActive(_isActive), ActivationTime(_activationTime), LeftSaber(_leftSaber), RightSaber(_rightSaber), Obstacle(_obstacle), Bomb(_bomb) {}
    )
}