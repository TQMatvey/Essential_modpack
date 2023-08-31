#pragma once
#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <Geode/modify/GameSoundManager.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/CCTransitionFade.hpp>

using namespace geode::prelude;

// Variables from settings
inline double TransitionsSpeed = Mod::get()->getSettingValue<double>("transitions-speed");
inline bool UnlockAllIcons = Mod::get()->getSettingValue<bool>("unlock-all-icons");
inline bool PracticeMusic = Mod::get()->getSettingValue<bool>("practice-music");