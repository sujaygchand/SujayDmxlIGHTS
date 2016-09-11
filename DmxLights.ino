void setDmxLights(int brightness, int red, int green, int blue, int fx1, int fx2) {
  DmxSimple.write(1, brightness);
  DmxSimple.write(2, red);
  DmxSimple.write(3, green);
  DmxSimple.write(4, blue);
  DmxSimple.write(5, fx1);
  DmxSimple.write(6, fx2);
}

void turnOffLights() {
  setDmxLights(0, 0, 0, 0, 0, 0);
}

void breathingLightEffect() {

  int brightness = 0;
  int randomRed = random(0, 256);
  int randomGreen = random(0, 256);
  int randomBlue = random(0, 256);
  boolean breakloop = false;
  boolean loopOneBreaker = false;
  boolean loopTwoBreaker = true;

  if (!breakloop && !loopOneBreaker) {
    for (int i = 0; i < 255; i++) {

      delay(10);
      Serial.println("PLUS");
      brightness++;
      setDmxLights(brightness, randomRed, randomGreen, randomBlue, 0, 0);

      if (brightness == 255) {
        loopTwoBreaker = false;
        loopOneBreaker = true;
      }

      if (digitalRead(SW_PIN) == HIGH) {
        breakloop = true;
        loopTwoBreaker = true;
        loopOneBreaker = true;
                         break;
        delay(10);
      }
    }
  }

  if (!breakloop && !loopTwoBreaker) {
    for (int i = 255; i > 0; i--) {
      delay(10);
      Serial.println("Minus");
      brightness--;
      setDmxLights(brightness, randomRed, randomGreen, randomBlue, 0, 0);


      if (brightness == 0) {
        loopTwoBreaker = true;
        loopOneBreaker = false;
      }

      if (digitalRead(SW_PIN) == HIGH) {
        breakloop = true;
        loopTwoBreaker = true;
        loopOneBreaker = true;
                         break;
        delay(10);
      }
    }
  }
}


void pulsingLightEffect() {

}



