#include "GlobalNamespace/BaseNoteVisuals.hpp"
#include "Hooks.hpp"


MAKE_AUTO_HOOK_MATCH(BaseNoteVisuals_Awake, &GlobalNamespace::BaseNoteVisuals::Awake, void, GlobalNamespace::BaseNoteVisuals *self)
{
    
    BaseNoteVisuals_Awake(self);
}