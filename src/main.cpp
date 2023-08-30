#include <main.h>

$on_mod(Loaded) {
	patchTransitions();
}

$execute {
	// from my observatiom. toglling any mod and clicking apply Restarts
	// the Mod, so $on_mod(Loaded) gets triggered with new values
	listenForSettingChanges("no-transitions", +[](bool val) {
		isNoTransitions = val;
	});

	listenForSettingChanges("unlock-all-icons", +[](bool val) {
		UnlockAllIcons = val;
	});
}