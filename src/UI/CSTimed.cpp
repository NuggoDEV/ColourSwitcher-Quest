#include "UI/CSTimed.hpp"
#include "Configuration/Config.hpp"
#include "Configuration/ModConfig.hpp"
#include "Logger.hpp"
#include "Models/TimedSwitch.hpp"
#include "assets.hpp"
#include "ColourSwitcher.hpp"
#include "Macros.hpp"

#include "bsml/shared/BSML.hpp"

#include "System/Collections/Generic/IReadOnlyList_1.hpp"
#define ReadOnlyList System::Collections::Generic::IReadOnlyList_1

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;
#define UColor UnityEngine::Color

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
        else
        {
            LeftSaberObject->set_interactable(false);
            RightSaberObject->set_interactable(false);
            ObstacleObject->set_interactable(false);
            BombObject->set_interactable(false);
        }
    }

    void CSTimed::ReloadSwitches()
    {
        List<StringW> *switchList = List<StringW>::New_ctor();
        for (int i = 0; i < config.TimedSwitches.size(); i++)
            switchList->Add(StringW("Switch " + std::to_string(i + 1)));

        // Cast the List<StringW>* to an IReadOnlyList<StringW>* and set values
        ReadOnlyList<StringW> *switches = reinterpret_cast<ReadOnlyList<StringW>*>(switchList);
        SwitchListObject->values = switches;
        SwitchListObject->dropdown->SetTexts(switches);
        SwitchListObject->UpdateChoices();
    }

    void CSTimed::AddSwitch()
    {
        config.TimedSwitches.emplace_back(Models::TimedSwitch());
        Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);
        ReloadSwitches();
        SwitchListObject->dropdown->set_selectedIndex(SwitchListObject->values.size() - 1);
    }

    void CSTimed::RemoveSwitch()
    {
        config.TimedSwitches.erase(config.TimedSwitches.begin() + SwitchListObject->index);
        Configuration::SaveConfig(getModConfig().SelectedConfig.GetValue(), config);
        ReloadSwitches();
        SwitchListObject->dropdown->set_selectedIndex(SwitchListObject->values.size() - 1); 
    }

    void CSTimed::SwitchSelected()
    {
        getLogger().info("%lu %i", config.TimedSwitches.size(), SwitchListObject->index);
        if (config.TimedSwitches.size() < SwitchListObject->index)
        {
            LeftSaberObject->set_interactable(false);
            RightSaberObject->set_interactable(false);
            ObstacleObject->set_interactable(false);
            BombObject->set_interactable(false);
        }
        else
        {
            getLogger().info("%lu", config.TimedSwitches.size());
            LeftSaberObject->set_interactable(true);
            RightSaberObject->set_interactable(true);
            ObstacleObject->set_interactable(true);
            BombObject->set_interactable(true);
            LeftSaberObject->set_currentColor(config.TimedSwitches[SwitchListObject->index].LeftSaber);
            RightSaberObject->set_currentColor(config.TimedSwitches[SwitchListObject->index].RightSaber);
            ObstacleObject->set_currentColor(config.TimedSwitches[SwitchListObject->index].Obstacle);
            BombObject->set_currentColor(config.TimedSwitches[SwitchListObject->index].Bomb);
        }
        
    }

    UI_VALUE(Color, CSTimed, LeftSaber, config.TimedSwitches.size() > 0 ? (UColor) config.TimedSwitches[SwitchListObject->index].LeftSaber : UColor::get_blue());
    UI_VALUE(Color, CSTimed, RightSaber, config.TimedSwitches.size() > 0 ? (UColor) config.TimedSwitches[SwitchListObject->index].RightSaber : UColor::get_blue());
    UI_VALUE(Color, CSTimed, Obstacle, config.TimedSwitches.size() > 0 ? (UColor) config.TimedSwitches[SwitchListObject->index].Obstacle : UColor::get_blue());
    UI_VALUE(Color, CSTimed, Bomb, config.TimedSwitches.size() > 0 ? (UColor) config.TimedSwitches[SwitchListObject->index].Bomb : UColor::get_blue());
}