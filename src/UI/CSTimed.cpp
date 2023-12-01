#include "UI/CSTimed.hpp"
#include "Configuration/Config.hpp"
#include "Configuration/ModConfig.hpp"
#include "Models/TimedSwitch.hpp"
#include "UnityEngine/Color.hpp"
#include "assets.hpp"
#include "ColourSwitcher.hpp"
#include "Macros.hpp"

#include "bsml/shared/BSML.hpp"

#include "System/Collections/Generic/IReadOnlyList_1.hpp"
#define ReadOnlyList System::Collections::Generic::IReadOnlyList_1

DEFINE_TYPE(ColourSwitcher::UI, CSTimed);

namespace ColourSwitcher::UI
{
    void CSTimed::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
    {
        if (!firstActivation)
            return;
        
        BSML::parse_and_construct(IncludedAssets::CSTimed_bsml, this->get_transform(), this);
    }

    void CSTimed::PostParse()
    {
        if (config.TimedSwitches.size() != 0)
            ReloadSwitches();
    }

    void CSTimed::ReloadSwitches()
    {
        List<StringW> *switchList = List<StringW>::New_ctor();
        for (int i = 0; i < config.TimedSwitches.size(); i++)
            switchList->Add(StringW("Switch " + std::to_string(i + 1)));
        SwitchListObject->values = reinterpret_cast<ReadOnlyList<StringW>*>(switchList);
        SwitchListObject->dropdown->SetTexts(reinterpret_cast<ReadOnlyList<StringW>*>(switchList));
        SwitchListObject->UpdateChoices();
    }

    void CSTimed::AddSwitch()
    {
        config.TimedSwitches.emplace_back(Models::TimedSwitch());
        Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);
        ReloadSwitches();
    }

    void CSTimed::RemoveSwitch()
    {
        config.TimedSwitches.erase(config.TimedSwitches.begin() + SwitchListObject->index);
        Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);
        ReloadSwitches();
    }

    //CONFIG_PROPERTY_TIMED(bool, CSTimed, IsActive, config, SwitchListObject->index, false);
    //CONFIG_PROPERTY_TIMED(int, CSTimed, ActivationTime, config, SwitchListObject->index, 0);
    CONFIG_PROPERTY_TIMED(UnityEngine::Color, CSTimed, LeftSaber, config, SwitchListObject->index, UnityEngine::Color::get_clear());
    CONFIG_PROPERTY_TIMED(UnityEngine::Color, CSTimed, RightSaber, config, SwitchListObject->index, UnityEngine::Color::get_clear());
    CONFIG_PROPERTY_TIMED(UnityEngine::Color, CSTimed, Obstacle, config, SwitchListObject->index, UnityEngine::Color::get_clear());
    CONFIG_PROPERTY_TIMED(UnityEngine::Color, CSTimed, Bomb, config, SwitchListObject->index, UnityEngine::Color::get_clear());
}