#include "main.h"

void patchUnlockAllIcons() {
	if(UnlockAllIcons) {
    	Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0xC50A8), {0xB0, 0x01, 0x90, 0x90, 0x90});   // Unlock All icons [1/2]
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0xC54BA), {0xB0, 0x01, 0x90, 0x90, 0x90});   // Unlock All icons [2/2]
	}
	else {
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0xC50A8), {0xE8, 0x7A, 0xCD, 0x19, 0x00});   // Revert Unlocked icons [1/2]
		Mod::get()->patch(reinterpret_cast<void*>(base::get() + 0xC54BA), {0xE8, 0x68, 0xC9, 0x19, 0x00});   // Revert Unlocked icons [2/2]
	}
}