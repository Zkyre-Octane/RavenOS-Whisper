#ifndef RAVEN_SOUND_H
#define RAVEN_SOUND_H

#include <Arduino.h>

class SoundManager {
public:

    /*
       Constructor
       Sets up the buzzer GPIO pin and LEDC PWM channel.
    */
    SoundManager(int buzzerPin, int pwmChannel);

    /*
       Core Control Functions
    */

    // Initialize PWM hardware and attach buzzer pin
    void ravenSoundInit();

    // Play a tone at a given frequency (Hz) for a duration (ms)
    void ravenPlayTone(int freq, int ms);

    // Immediately stop any tone output
    void ravenStopSound();


    /*
       System Sounds (UI / OS Feedback)
    */

    void ravenSoundBoot();         // Boot jingle
    void ravenSoundBeep();         // Simple short beep
    void ravenSoundError();        // Error tone pattern
    void ravenSoundTaskComplete(); // Success tone pattern
    void ravenSoundShutdown();     // Shutdown tone pattern
    void ravenSoundNotify();       // Notification tone pattern
    void ravenSoundClick();        // UI click tone


    /*
       Pairing / Connectivity Melodies
    */

    void ravenSoundNfcPairing();     // NFC pairing melody
    void ravenSoundEspNowPairing();  // ESP-NOW pairing melody
    void ravenSoundWifiPairing();    // WiFi pairing melody


    /*
       Vehicle / FPV / Robotics Sounds
    */

    void ravenSoundArm();     //  arming tone
    void ravenSoundDisarm();  //  disarm tone
    void ravenSoundBeacon();  //  beacon pulse

private:
    int _pin;
    int _channel;
};

#endif
