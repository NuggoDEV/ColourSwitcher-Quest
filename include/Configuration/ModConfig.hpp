#pragma once

#include "config-utils/shared/config-utils.hpp"
#include <string>

DECLARE_CONFIG(ModConfig, 
    CONFIG_VALUE(SelectedConfig, std::string, "SelectedConfig", "Default");
)