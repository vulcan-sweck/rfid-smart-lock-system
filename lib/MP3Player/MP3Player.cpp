#include "MP3Player.h"

MP3Player::MP3Player(uint8_t rx, uint8_t tx)
{
    rxPin = rx;
    txPin = tx;
    mp3Serial = new SoftwareSerial(rxPin, txPin);
}

bool MP3Player::begin(uint32_t baud)
{
    mp3Serial->begin(baud);

    if (!dfPlayer.begin(*mp3Serial))
    {
        return false;
    }

    dfPlayer.volume(20);
    dfPlayer.EQ(DFPLAYER_EQ_NORMAL);

    return true;
}

void MP3Player::start(uint16_t track)
{
    dfPlayer.play(track);
}

void MP3Player::stop()
{
    dfPlayer.stop();
}

void MP3Player::pause()
{
    dfPlayer.pause();
}

void MP3Player::resume()
{
    dfPlayer.start();
}

void MP3Player::setVolume(uint8_t volume)
{
    if (volume > 30) volume = 30;
    dfPlayer.volume(volume);
}