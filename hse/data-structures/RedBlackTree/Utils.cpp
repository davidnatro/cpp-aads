#include "Utils.h"

int Utils::getRandomNumber(int min, int max) {
    return rand() % (max + 1 - min) + min;
}