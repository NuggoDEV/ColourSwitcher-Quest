#pragma once

#include "sombrero/shared/ColorUtils.hpp"
#include "GlobalNamespace/ColorType.hpp"

namespace ColourSwitcher
{
    class ColourManager
    {
        public:
        static void BombColourize(Sombrero::FastColor colour);
        static void SaberColourize(Sombrero::FastColor colour, GlobalNamespace::ColorType colourType);
        static void NoteColourize(Sombrero::FastColor colour, GlobalNamespace::ColorType colourType);
        static void ObstacleColourize(Sombrero::FastColor colour);
    };
}