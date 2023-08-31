#include <main.h>

$on_mod(Loaded) {
}

$execute {
	listenForSettingChanges("transitions-speed", +[](double val) {
		TransitionsSpeed = val;
	});

	listenForSettingChanges("unlock-all-icons", +[](bool val) {
		UnlockAllIcons = val;
	});

	listenForSettingChanges("practice-music", +[](bool val) {
		PracticeMusic = val;
	});
}