#pragma once
#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

// Variables from settings
static bool isNoTransitions = Mod::get()->getSettingValue<bool>("no-transitions");
static bool UnlockAllIcons = Mod::get()->getSettingValue<bool>("unlock-all-icons");

// No Trasitions 
void patchTransitions();