#include "ColourSwitcher.hpp"
#include "Hooks.hpp"

#include "Configuration/ModConfig.hpp"
#include "Configuration/Config.hpp"
#include "Logger.hpp"
#include "UI/CSFlow.hpp"
#include "bsml/shared/BSML.hpp"
#include "chroma/shared/utils.hpp"
#include "custom-types/shared/register.hpp"
#include "modloader/shared/modloader.hpp"

#include "chroma/shared/CoreAPI.hpp"

ColourSwitcher::Configuration::Config config;
static ModInfo modInfo = ModInfo{ MOD_ID, VERSION };
static Logger* logger = new Logger(modInfo, LoggerOptions(false, true));

Logger& ColourSwitcher::getLogger() {
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info = modInfo;
}

extern "C" void load() {
    il2cpp_functions::Init();
    getModConfig().Init(modInfo);
    ColourSwitcher::getLogger().init();
    custom_types::Register::AutoRegister();

    BSML::Register::RegisterMainMenu<ColourSwitcher::UI::CSFlow*>("Colour Switcher", "Funni");
    ColourSwitcher::Configuration::LoadConfig(getModConfig().SelectedConfig.GetValue(), config);

    Hooks::InstallHooks(ColourSwitcher::getLogger());

    if (Modloader::getMods().contains("chroma"))
        Chroma::CoreAPI::addForceEnableChromaHooks(modInfo);
}