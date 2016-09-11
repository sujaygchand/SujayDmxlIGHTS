#include <DmxSimple.h>

const byte DMX_PIN = 2;
const byte SW_PIN = 3;

boolean swCurrent = LOW;
boolean swPrevious = LOW;

int configuration = 0;
int numConfigurations = 7;

boolean switchState = false;

void setup() {

  DmxSimple.usePin(DMX_PIN);
  DmxSimple.maxChannel(6);

  Serial.begin(9600);

  pinMode(SW_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(SW_PIN), CHANGE , RISING);
}

void loop() {

  //  Serial.print("there: ");
  //  Serial.println(switchState);

  Serial.print("configuration: ");
  Serial.println(configuration);
  swCurrent = debounce(swPrevious);

  //Serial.print("swCurrent: ");
  //Serial.println(swCurrent);
  //
  //Serial.print("swPrevious: ");
  //Serial.println(swPrevious);

//  if (digitalRead(SW_PIN) == HIGH)
//    Serial.println("wgfdfsvd erfdvsdvesdvxczg");
    if (swPrevious == LOW && swCurrent == HIGH) {
      configuration++;
      switchState = true;
      Serial.print("Here: ");
      Serial.println(switchState);
    }
  else {
    switchState = false;
  }
  swPrevious = swCurrent;


  if (configuration > numConfigurations) {
    configuration = 0;
  }

  switch (configuration) {
    case 0 :
      turnOffLights();
      break;
    // Red
    case 1 :
      setDmxLights(255, 255, 0, 0, 0, 0);
      break;
    // Green
    case 2 :
      setDmxLights(255, 0, 255, 0, 0, 0);
      break;
    // Blue
    case 3 :
      setDmxLights(255, 0, 0, 255, 0, 0);
      break;
    // Purple
    case 4 :
      setDmxLights(255, 0, 0, 255, 0, 0);
      break;
    case 5 :
      setDmxLights(255, 255, 0, 255, 0, 0);
      break;
    case 6 :
      breathingLightEffect();
      break;
    case 7:
      setDmxLights(255, 125, 125, 0, 0, 0);
      break;

  }
}

