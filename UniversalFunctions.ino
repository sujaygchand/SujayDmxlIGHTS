boolean debounce(boolean previousState){
  boolean currentState = digitalRead(SW_PIN);

  if (previousState != currentState)
  {
    delay(5);
    currentState = digitalRead(SW_PIN);
  }
  return currentState;
}

