#pragma once
#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameSoundManager.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

// Variables from settings
inline bool isNoTransitions = Mod::get()->getSettingValue<bool>("no-transitions");
inline bool UnlockAllIcons = Mod::get()->getSettingValue<bool>("unlock-all-icons");
inline bool PracticeMusic = Mod::get()->getSettingValue<bool>("practice-music");

// No Trasitions 
void patchTransitions();