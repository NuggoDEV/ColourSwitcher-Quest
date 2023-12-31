#pragma once

#include "custom-types/shared/macros.hpp"

#include "HMUI/ViewController.hpp"

#include "beatsaber-hook/shared/utils/il2cpp-utils-methods.hpp"
#include "beatsaber-hook/shared/utils/typedefs.h"

#include "bsml/shared/macros.hpp"
#include "bsml/shared/BSML.hpp"
#include "bsml/shared/BSML/Components/Settings/DropdownListSetting.hpp"
#include "bsml/shared/BSML/Components/Settings/ColorSetting.hpp"


DECLARE_CLASS_CODEGEN(ColourSwitcher::UI, CSTimed, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_INSTANCE_METHOD(void, PostParse);
    DECLARE_INSTANCE_METHOD(void, ReloadSwitches);
    DECLARE_INSTANCE_METHOD(void, AddSwitch);
    DECLARE_INSTANCE_METHOD(void, RemoveSwitch);
    DECLARE_INSTANCE_METHOD(void, SwitchSelected);

    DECLARE_INSTANCE_FIELD(BSML::DropdownListSetting*, SwitchListObject);

    BSML_OPTIONS_LIST_STRING(SwitchList, "None");

    DECLARE_BSML_PROPERTY(UnityEngine::Color, LeftSaber);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, RightSaber);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, Obstacle);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, Bomb);

    DECLARE_INSTANCE_FIELD(BSML::ColorSetting*, LeftSaberObject);
    DECLARE_INSTANCE_FIELD(BSML::ColorSetting*, RightSaberObject);
    DECLARE_INSTANCE_FIELD(BSML::ColorSetting*, ObstacleObject);
    DECLARE_INSTANCE_FIELD(BSML::ColorSetting*, BombObject);
)