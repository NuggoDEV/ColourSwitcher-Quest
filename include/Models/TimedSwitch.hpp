#pragma once

#include "rapidjson-macros/shared/macros.hpp"
#include "Models/Color.hpp"

namespace ColourSwitcher::Models
{
    DECLARE_JSON_CLASS(TimedSwitch, 
        VALUE_DEFAULT(bool, IsActive, false);
        VALUE_DEFAULT(int, ActivationTime, 0);
        VALUE_DEFAULT(Color, LeftSaber, Color());
        VALUE_DEFAULT(Color, RightSaber, Color());
        VALUE_DEFAULT(Color, Obstacle, Color());
        VALUE_DEFAULT(Color, Bomb, Color());

        TimedSwitch() = default;
        TimedSwitch(bool _isActive, int _activationTime, Color _leftSaber, Color _rightSaber, Color _obstacle, Color _bomb) : 
            IsActive(_isActive), ActivationTime(_activationTime), LeftSaber(_leftSaber), RightSaber(_rightSaber), Obstacle(_obstacle), Bomb(_bomb) {}
    )
}