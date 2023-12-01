#include "ColourSwitcher.hpp"
#include "Hooks.hpp"

#include "Configuration/ModConfig.hpp"
#include "Configuration/Config.hpp"
#include "UI/CSFlow.hpp"
#include "bsml/shared/BSML.hpp"
#include "custom-types/shared/register.hpp"

ColourSwitcher::Configuration::Config config;
static ModInfo modInfo = ModInfo{ MOD_ID, VERSION };
static Logger* logger = new Logger(modInfo, LoggerOptions(false, true));

Logger& getLogger() {
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info = modInfo;
}

extern "C" void load() {
    il2cpp_functions::Init();
    getModConfig().Init(modInfo);
    custom_types::Register::AutoRegister();

    BSML::Register::RegisterMainMenu<ColourSwitcher::UI::CSFlow*>("Colour Switcher", "Funni");
    ColourSwitcher::Configuration::LoadConfig(getModConfig().SelectedConfig.GetValue(), config);

    Hooks::InstallHooks(getLogger());
}