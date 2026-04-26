#include <Arduino.h>
#include "MP3Player.h"
#include "RFIDReader.h"
#include <Definitions.h>


MP3Player player(MP3_RX, MP3_TX);
RFIDReader rfid(RFID_SS_PIN, RFID_RST_PIN);


void setup()
{
    Serial.begin(9600);
    pinMode(DOOR_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    rfid.begin();
    if (!player.begin())
    {
        Serial.println("DFPlayer not detected!");
        while (true);
    }

    player.setVolume(30);
    player.start(1);   // plays 0001.mp3
}

void loop()
{
    if (rfid.readCard(scannedUID))
    {
        rfid.printCardID(scannedUID);

        if (rfid.isAllowed(scannedUID))
        {
            Serial.println("Access Granted");

            digitalWrite(DOOR_PIN, HIGH);
            delay(3000);
            digitalWrite(DOOR_PIN, LOW);
        }
        else
        {
            Serial.println("Access Denied");

            digitalWrite(BUZZER_PIN, HIGH);
            delay(500);
            digitalWrite(BUZZER_PIN, LOW);
        }
    }
}