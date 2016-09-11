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


void pulsingLightEffect(int randomNum) {
  int modeNum = randomNum;
  int brightness = 0;

  boolean breakloop = false;
  boolean loopOneBreaker;
  boolean loopTwoBreaker;
  boolean loopThreeBreaker;
  boolean loopFourBreaker;


  int ranBrightness;
  int ranRed;
  int ranGreen;
  int ranBlue;

  while (!breakloop) {
    if (digitalRead(SW_PIN) == HIGH) {
      breakloop = true;
      loopOneBreaker = true;
      loopTwoBreaker = true;
      loopThreeBreaker = true;
      loopFourBreaker = true;
      break;
    }

    if (modeNum < 0 || modeNum > 7) {
      modeNum = 0;
    }

    if (modeNum == 0 || modeNum == 1 && !loopOneBreaker) {
      for (int brightness = 0; brightness <= 255 ; brightness++) {
        delay(5);
        setDmxLights(brightness, 125, 125, 0, 0, 0);

        if (digitalRead(SW_PIN) == HIGH) {
          breakloop = true;
          loopOneBreaker = true;
          loopTwoBreaker = true;
          loopThreeBreaker = true;
          loopFourBreaker = true;
          break;
        }

        if (brightness == 254)
        {
          delay(30);
          modeNum++;
          if (modeNum > 1) {
            loopOneBreaker = true;
            loopTwoBreaker = false;
            loopThreeBreaker = true;
            loopFourBreaker = true;
          }
        }
      }
    }

    if (modeNum == 2 || modeNum == 3 && !loopTwoBreaker) {
      for (int brightness = 0; brightness <= 200 ; brightness++) {
        delay(5);
        setDmxLights(brightness, 120, 20, 190, 0, 0);

        if (digitalRead(SW_PIN) == HIGH) {
          breakloop = true;
          loopOneBreaker = true;
          loopTwoBreaker = true;
          loopThreeBreaker = true;
          loopFourBreaker = true;
          break;
        }

        if (brightness == 199)
        {
          delay(30);
          modeNum++;
          if (modeNum > 3) {
            loopOneBreaker = true;
            loopTwoBreaker = true;
            loopThreeBreaker = false;
            loopFourBreaker = true;
          }
        }
      }
    }

    if (modeNum == 4 || modeNum == 5 && !loopThreeBreaker) {
      for (int brightness = 0; brightness <= 255 ; brightness++) {
        delay(5);
        setDmxLights(brightness, 200, 50, 70, 0, 0);

        if (digitalRead(SW_PIN) == HIGH) {
          breakloop = true;
          loopOneBreaker = true;
          loopTwoBreaker = true;
          loopThreeBreaker = true;
          loopFourBreaker = true;
          break;
        }

        if (brightness == 254)
        {
          delay(30);
          modeNum++;
          if (modeNum > 5) {
            loopOneBreaker = true;
            loopTwoBreaker = true;
            loopThreeBreaker = true;
            loopFourBreaker = false;
            ranBrightness = random(180, 256);
            ranRed = random(0, 256);
            ranGreen = random(0, 256);
            ranBlue = random(0, 256);
          }
        }
      }
    }

    if (modeNum == 6 || modeNum == 7 && !loopFourBreaker) {
      if (ranRed < 20 && ranGreen < 20 && ranBlue < 20) {
        ranRed = 240;
      }

      for (int brightness = 0; brightness <= ranBrightness; brightness++) {
        delay(5);
        setDmxLights(brightness, ranRed, ranGreen, ranBlue, 0, 0);

        if (digitalRead(SW_PIN) == HIGH) {
          breakloop = true;
          loopOneBreaker = true;
          loopTwoBreaker = true;
          loopThreeBreaker = true;
          loopFourBreaker = true;
          break;
        }

        if (brightness == ranBrightness - 1)
        {
          delay(30);
          modeNum++;
          if (modeNum > 7) {
            modeNum = 0;
            loopOneBreaker = false;
            loopTwoBreaker = true;
            loopThreeBreaker = true;
            loopFourBreaker = true;
          }
        }
      }
    }
  }
//
//if(breakloop){
//  configuration = 8
//}
  
}

void discoLights() {

  boolean breakLoop = false;

  while (!breakLoop) {
    for (int fx1 = 0; fx1 > 255; fx1++) {
      delay(50);
      setDmxLights(255, 120, 20, 190, fx1, 0);

      if (digitalRead(SW_PIN) == HIGH) {
        breakLoop = true;
        break;
      }
    }
  }
}



