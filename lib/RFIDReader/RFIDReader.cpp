#include "RFIDReader.h"


RFIDReader::RFIDReader(byte ssPin, byte rstPin)
    : mfrc522(ssPin, rstPin)
{
}

void RFIDReader::begin()
{
    SPI.begin();
    mfrc522.PCD_Init();
}

bool RFIDReader::readCard(byte *uid)
{
    if (!mfrc522.PICC_IsNewCardPresent())
        return false;

    if (!mfrc522.PICC_ReadCardSerial())
        return false;

    for (byte i = 0; i < UID_LENGTH; i++)
    {
        uid[i] = mfrc522.uid.uidByte[i];
    }

    mfrc522.PICC_HaltA();

    return true;
}

void RFIDReader::printCardID(byte *uid)
{
    Serial.print("Card UID: ");

    for (byte i = 0; i < UID_LENGTH; i++)
    {
        Serial.print("0x");
        if (uid[i] < 0x10) Serial.print("0");
        Serial.print(uid[i], HEX);

        if (i < UID_LENGTH - 1)
            Serial.print(", ");
    }

    Serial.println();
}

bool RFIDReader::isAllowed(byte *uid)
{
    for (int i = 0; i < allowedCardCount; i++)
    {
        bool match = true;

        for (int j = 0; j < UID_LENGTH; j++)
        {
            if (allowedCards[i][j] != uid[j])
            {
                match = false;
                break;
            }
        }

        if (match)
            return true;
    }

    return false;
}