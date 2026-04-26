#pragma once

#include <Arduino.h>

/* ---------------- PIN DEFINITIONS ---------------- */

#define RFID_SS_PIN 10
#define RFID_RST_PIN 9


#define MP3_RX 5
#define MP3_TX 6

#define DOOR_PIN 3
#define BUZZER_PIN 4


/* ---------------- RFID CARD STORAGE ---------------- */

#define MAX_CARDS 10
#define UID_LENGTH 4

extern byte allowedCards[MAX_CARDS][UID_LENGTH];
extern int allowedCardCount;
extern byte scannedUID[UID_LENGTH];

