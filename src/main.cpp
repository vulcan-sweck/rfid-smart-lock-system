#include <Arduino.h>
#include "MP3Player.h"
#include "RFIDReader.h"
#include <Definitions.h>


MP3Player player(MP3_RX, MP3_TX);
RFIDReader rfid(RFID_SS_PIN, RFID_RST_PIN);

//1 is for access granted
//2 is for access denied
//3 is for welcome message
void setup()
{
    Serial.begin(9600);
    pinMode(DOOR_PIN, OUTPUT);

    rfid.begin();
    if (!player.begin())
    {
        Serial.println("DFPlayer not detected!");
        while (true);
    }
}

void loop()
{

    if (rfid.readCard(scannedUID))
    {
        rfid.printCardID(scannedUID);

        if (rfid.isAllowed(scannedUID))
        {
            Serial.println("Access Granted");
            player.setVolume(30);
            player.start(1);
            delay(2000);
            player.start(3);
            
            digitalWrite(DOOR_PIN, HIGH);
            Serial.println("Door Opened");
            delay(3000);
            digitalWrite(DOOR_PIN, LOW);
            Serial.println("Door Closed");
        }
        else
        {
            Serial.println("Access Denied");
            player.setVolume(30);
            player.start(2);
        }
    }
}