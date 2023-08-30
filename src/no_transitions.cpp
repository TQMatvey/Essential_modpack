#include "main.h"

void patchTransitions() {
	if(isNoTransitions)
    	Mod::get()->patch(reinterpret_cast<void*>(base::getCocos() + 0xA5424), {0x90, 0x90, 0x90, 0x90, 0x90});   // No transitions
    else
		Mod::get()->patch(reinterpret_cast<void*>(base::getCocos() + 0xA5424), {0xF3, 0x0F, 0x10, 0x45, 0x08});   // Default Transitions
}