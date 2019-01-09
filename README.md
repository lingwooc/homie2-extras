# homie2-extras
Cleaner setup wrapper for homie implementation on eps8266

Example code for a socket with a button (events just go to MQTT, needs additional logic)
```
#include <HomieExtras.hpp>

#define PLUG_RELAY 12
#define BUTTON_PIN 0

DigitalOutNode plugNode("plug", PLUG_RELAY, HIGH);
DigitalInEventNode buttonNode("button", BUTTON_PIN);

void setup()
{
  Serial.begin(115200);
  Serial << endl
         << endl;

  Homie_setFirmware("mqtt-plug", "1.0.0");

  HomieExtras::setup();
  Homie.setup();
}

void loop()
{
  Homie.loop();
}
```
