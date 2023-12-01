#include "UI/CSFlow.hpp"
#include "UI/CSMain.hpp"
#include "UI/CSTimed.hpp"
#include "ColourSwitcher.hpp"

#include "Configuration/Config.hpp"
#include "Configuration/ModConfig.hpp"
#include "Logger.hpp"

using namespace ColourSwitcher::UI;

#include "HMUI/ViewController_AnimationDirection.hpp"
#include "HMUI/ViewController_AnimationType.hpp"

#include "bsml/shared/Helpers/creation.hpp"

DEFINE_TYPE(ColourSwitcher::UI, CSFlow);

void CSFlow::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (!firstActivation)
        return;
    INFO("Activating Flow Coordinator");
    
    mainView = BSML::Helpers::CreateViewController<CSMain*>();
    timedView = BSML::Helpers::CreateViewController<CSTimed*>();

    showBackButton = true;
    
    ProvideInitialViewControllers(mainView, nullptr, timedView, nullptr, nullptr);
    SetTitle("Colour Switcher Settings", HMUI::ViewController::AnimationType::In);
}

void CSFlow::BackButtonWasPressed(HMUI::ViewController *topViewController)
{
    Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);
    this->parentFlowCoordinator->DismissFlowCoordinator(this, HMUI::ViewController::AnimationDirection::Horizontal, nullptr, false);
}