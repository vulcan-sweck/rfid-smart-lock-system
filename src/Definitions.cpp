#include "Definitions.h"

byte allowedCards[MAX_CARDS][UID_LENGTH] =
{
    {0x93, 0xA7, 0x2F, 0x11},
    {0x52, 0x8C, 0x9A, 0x3D}
};

int allowedCardCount = 2;

byte scannedUID[UID_LENGTH];



