#pragma once

#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Definitions.h>

class RFIDReader
{
private:
    MFRC522 mfrc522;


public:

    RFIDReader(byte ssPin, byte rstPin);

    void begin();

    bool readCard(byte *uid);

    void printCardID(byte *uid);

    bool isAllowed(byte *uid);
};