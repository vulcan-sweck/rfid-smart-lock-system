#pragma once

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

class MP3Player
{
private:
    SoftwareSerial *mp3Serial;
    DFRobotDFPlayerMini dfPlayer;

    uint8_t rxPin;
    uint8_t txPin;

public:
    MP3Player(uint8_t rx, uint8_t tx);

    bool begin(uint32_t baud = 9600);

    void start(uint16_t track);   // play track
    void stop();                  // stop playback
    void pause();                 // pause playback
    void resume();                // resume playback
    void setVolume(uint8_t volume);
};