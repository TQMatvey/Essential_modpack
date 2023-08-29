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
bool UnlockAllIcons = Mod::get()->getSettingValue<bool>("unlock-all-icons");

void patchTransitions() {					// Hex patch Hacks ported from MHv6
	log::info("isNoTransitions state: {}", isNoTransitions);
	if(isNoTransitions)
    	Mod::get()->patch(reinterpret_cast<void*>(base::getCocos() + 0xA5424), {0x90, 0x90, 0x90, 0x90, 0x90});   // No transitions
    else
		Mod::get()->patch(reinterpret_cast<void*>(base::getCocos() + 0xA5424), {0xF3, 0x0F, 0x10, 0x45, 0x08});   // Default Transitions
}

void patchUnlockAllIcons() {					// Hex patch Hacks ported from MHv6
	log::info("UnlockAllIcons state: {}", UnlockAllIcons);
	if(UnlockAllIcons) {
    	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0xC50A8), {0xB0, 0x01, 0x90, 0x90, 0x90});   // Unlock All icons [1/2]
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0xC54BA), {0xB0, 0x01, 0x90, 0x90, 0x90});   // Unlock All icons [2/2]
	}
	else {
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0xC50A8), {0xE8, 0x7A, 0xCD, 0x19, 0x00});   // Revert Unlocked icons [1/2]
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0xC54BA), {0xE8, 0x68, 0xC9, 0x19, 0x00});   // Revert Unlocked icons [2/2]
	}
}

$on_mod(Loaded) {
	patchTransitions();
	patchUnlockAllIcons();
}

$execute {
	listenForSettingChanges("no-transitions", +[](bool val) {
		isNoTransitions = val;
        patchTransitions();
	});

	listenForSettingChanges("unlock-all-icons", +[](bool val) {
		UnlockAllIcons = val;
        patchUnlockAllIcons();
	});
}