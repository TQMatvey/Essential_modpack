/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>
#include <Geode/loader/SettingEvent.hpp>

/**
 * Brings cocos2d and all Geode namespaces 
 * to the current scope.
 */
using namespace geode::prelude;

bool isNoTransitions = Mod::get()->getSettingValue<bool>("no-transitions");

void patchTransitions() {					// Hex patch Hacks ported from MHv6
	log::info("isNoTransitions state: {}", isNoTransitions);
	if(isNoTransitions)
    	Mod::get()->patch(reinterpret_cast<void*>(base::getCocos() + 0xA5424), {0x90, 0x90, 0x90, 0x90, 0x90});   // No transitions
    else
		Mod::get()->patch(reinterpret_cast<void*>(base::getCocos() + 0xA5424), {0xF3, 0x0F, 0x10, 0x45, 0x08});   // Default Transitions
}

$on_mod(Loaded) {
	patchTransitions();
}

$execute {
	listenForSettingChanges("no-transitions", +[](bool val) {
		isNoTransitions = val;
        patchTransitions();
	});
}