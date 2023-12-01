#include "Configuration/Config.hpp"
#include "Configuration/ModConfig.hpp"
#include "Logger.hpp"
using namespace ColourSwitcher::Constants;

#include <exception>

namespace ColourSwitcher::Configuration
{
    void LoadConfig(std::string fileName, Config& config)
    {
        mkpath(ConfigPath);
        std::string configPath = ConfigPath + fileName + ".json";
        try
        {
            ReadFromFile(configPath, config);
        }
        catch (std::exception err)
        {
            CreateConfig("Default");
            getModConfig().SelectedConfig.SetValue("Default");
            LoadConfig(fileName, config);
        }        
    }

    void SaveConfig(std::string fileName, Config config)
    {
        std::string configPath = ConfigPath + fileName + ".json";
        INFO("Saving config to path %s", configPath);
        WriteToFile(configPath, config);
    }

    void CreateConfig(std::string fileName)
    {
        std::string configPath = ConfigPath + fileName + ".json";
        WriteToFile(configPath, Configuration::Config());
    }

    void CreateConfig(std::string fileName, Configuration::Config config)
    {
        std::string configPath = ConfigPath + fileName + ".json";
        WriteToFile(configPath, config);
    }
}