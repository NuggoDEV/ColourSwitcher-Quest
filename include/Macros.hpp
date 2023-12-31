#pragma once

#include "Configuration/ModConfig.hpp"

#include "UnityEngine/Color.hpp"

namespace ColourSwitcher
{
    #define UI_VALUE(type, class, function, configVal)                                  \
    type class::get_##function() { return configVal; }                                  \
    void class::set_##function(type value) {                                            \
        configVal = value;                                                              \
        Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);    \
    }

    #define CONFIG_VAL config.TimedSwitches[SwitchListObject->dropdown->get_selectedIndex()]
}