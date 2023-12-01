#pragma once

#include "Constants.hpp"
#include "Models/TimedSwitch.hpp"
#include "Models/Color.hpp"

#include "rapidjson-macros/shared/macros.hpp"
#include <string>

namespace ColourSwitcher::Configuration
{
    DECLARE_JSON_CLASS(Config,
        VALUE_DEFAULT(std::string, Version, Constants::ConfigVersion);
        VALUE_DEFAULT(Models::Color, Bomb, Models::Color());
        VECTOR_DEFAULT(Models::TimedSwitch, TimedSwitches, {});

        Config() = default;
        Config(Models::Color _Bomb, std::vector<Models::TimedSwitch> _TimedSwitches) : Version(Constants::ConfigVersion), Bomb(_Bomb), TimedSwitches(_TimedSwitches) {}
    )

    void LoadConfig(std::string fileName, Config& config);
    void SaveConfig(std::string fileName, Config config);
    void CreateConfig(std::string fileName);
    void CreateConfig(std::string fileName, Configuration::Config config);
}