#include <main.h>

class $modify(GameManager) {
    bool isIconUnlocked(int a, IconType b) {
        auto icon = GameManager::isIconUnlocked(a,b);
        if (UnlockAllIcons)
            return true;
        else
            return icon;
    } 

    bool isColorUnlocked(int a, bool b) {
        auto color = GameManager::isColorUnlocked(a,b);
        if (UnlockAllIcons)
            return true;
        else
            return color;
    }
};