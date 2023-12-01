#pragma once

#include "Configuration/ModConfig.hpp"

#include "UnityEngine/Color.hpp"

namespace ColourSwitcher
{
    #define CONFIG_PROPERTY_TIMED(type, class, name, config, position, defaultValue)                                                            \
    type class::get_##name() { return config.TimedSwitches.size() < position ? (type) config.TimedSwitches[position].name : defaultValue; }     \
    void class::set_##name(type value)                                                                                                          \
    {                                                                                                                                           \
        if (config.TimedSwitches.size() < position)                                                                                             \
        config.TimedSwitches[position].name = value;                                                                                            \
        Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);                                                            \
    }

    #define CONFIG_PROPERTY(type, class, name, config)                                  \
    type class::get_##name() { return config.name; }                                    \
    void class::set_##name(type value)                                                  \
    {                                                                                   \
        config.name = value;                                                            \
        Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);    \
    }

    #define COLOURSCHEME_PROPERTY(type, class, name, colourSchemeName, colourScheme)    \
    type class::get_##name() { return colourScheme->get_##colourSchemeName(); }         \
    void class::set_##name(type value)                                                  \
    {                                                                                   \
        colourScheme->colourSchemeName = value;                                         \
        Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);    \
    }
}