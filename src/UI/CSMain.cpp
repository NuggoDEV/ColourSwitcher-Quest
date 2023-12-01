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
using namespace GlobalNamespace;

#include "bsml/shared/BSML.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DEFINE_TYPE(ColourSwitcher::UI, CSMain);

namespace ColourSwitcher::UI {
    ColorScheme *colourScheme;

	void CSMain::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling) {
		if (!firstActivation) return;
		colourScheme = FindObjectOfType<PlayerDataModel*>()->playerData->colorSchemesSettings->GetSelectedColorScheme();

		BSML::parse_and_construct(IncludedAssets::CSMain_bsml, this->get_transform(), this);
	}

	COLOURSCHEME_PROPERTY(Color, CSMain, LeftSaber, saberAColor, colourScheme);
	COLOURSCHEME_PROPERTY(Color, CSMain, RightSaber, saberBColor, colourScheme);
	COLOURSCHEME_PROPERTY(Color, CSMain, Obstacle, saberBColor, colourScheme);
	CONFIG_PROPERTY(Color, CSMain, Bomb, config);
} // namespace ColourSwitcher::UI