#pragma once
#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>

using namespace geode::prelude;

// Variables from settings
static bool isNoTransitions = Mod::get()->getSettingValue<bool>("no-transitions");
static bool UnlockAllIcons = Mod::get()->getSettingValue<bool>("unlock-all-icons");

// Unlock All Icons
void patchUnlockAllIcons();

// No Trasitions 
void patchTransitions();