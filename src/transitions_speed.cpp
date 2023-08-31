#include <main.h>

class $modify(CCTransitionFade) {
	static CCTransitionFade* create(float duration,CCScene* scene) {
		return CCTransitionFade::create(TransitionsSpeed, scene);
	}
};