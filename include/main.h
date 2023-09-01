#pragma once
#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameSoundManager.hpp>
#include <Geode/modify/GameManager.hpp>

using namespace geode::prelude;

// Variables from settings
static bool isNoTransitions = Mod::get()->getSettingValue<bool>("no-transitions");
static bool UnlockAllIcons = Mod::get()->getSettingValue<bool>("unlock-all-icons");
static bool PracticeMusic = Mod::get()->getSettingValue<bool>("practice-music");

// No Trasitions 
void patchTransitions();