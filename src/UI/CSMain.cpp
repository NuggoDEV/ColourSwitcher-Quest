#include "UI/CSMain.hpp"
#include "Configuration/Config.hpp"
#include "assets.hpp"
#include "Macros.hpp"
#include "Logger.hpp"
#include "ColourSwitcher.hpp"

#include "GlobalNamespace/ColorSchemesSettings.hpp"
#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include <new>
using namespace GlobalNamespace;

#include "bsml/shared/BSML.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

#include <string>

DEFINE_TYPE(ColourSwitcher::UI, CSMain);

namespace ColourSwitcher::UI {
    ColorScheme *colourScheme = nullptr;
	std::string potat = "Default";

	void CSMain::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
		if (!firstActivation) return;
		colourScheme = FindObjectOfType<PlayerDataModel*>()->playerData->colorSchemesSettings->GetSelectedColorScheme();

		BSML::parse_and_construct(IncludedAssets::CSMain_bsml, this->get_transform(), this);
	}

	void CSMain::SaveConfig()
	{
		getLogger().info("%s", potat.c_str());
		Configuration::SaveConfig(potat, config);
	}

	UI_VALUE(Color, CSMain, LeftSaber, colourScheme->saberAColor);
	UI_VALUE(Color, CSMain, RightSaber, colourScheme->saberBColor);
	UI_VALUE(Color, CSMain, Obstacle, colourScheme->obstaclesColor);
	UI_VALUE(Color, CSMain, Bomb, config.Bomb);
	StringW CSMain::get_ConfigName() { return static_cast<StringW>(potat); }
	void CSMain::set_ConfigName(StringW value) {
	  	potat = static_cast<std::string>(value);
		getLogger().info("%s", potat.c_str());
	}
} // namespace ColourSwitcher::UI