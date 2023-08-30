#include <main.h>

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