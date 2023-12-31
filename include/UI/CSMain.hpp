#pragma once

#include "UnityEngine/Color.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils-methods.hpp"
#include "custom-types/shared/macros.hpp"
#include "bsml/shared/BSML.hpp"
#include "HMUI/ViewController.hpp"

DECLARE_CLASS_CODEGEN(ColourSwitcher::UI, CSMain, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_INSTANCE_METHOD(void, SaveConfig);

    DECLARE_BSML_PROPERTY(UnityEngine::Color, LeftSaber);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, RightSaber);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, Obstacle);
    DECLARE_BSML_PROPERTY(UnityEngine::Color, Bomb);

    DECLARE_BSML_PROPERTY(StringW, ConfigName);
)