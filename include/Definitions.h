#pragma once

#include <Arduino.h>

/* ---------------- PIN DEFINITIONS ---------------- */

#define RFID_SS_PIN 10
#define RFID_RST_PIN 9


#define MP3_RX 6
#define MP3_TX 5

#define DOOR_PIN 3


/* ---------------- RFID CARD STORAGE ---------------- */

#define MAX_CARDS 10
#define UID_LENGTH 4

extern byte allowedCards[MAX_CARDS][UID_LENGTH];
extern int allowedCardCount;
extern byte scannedUID[UID_LENGTH];

