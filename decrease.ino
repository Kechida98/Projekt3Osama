void DecreaseBetPress() {
  static bool decreaseButtonPressed = false;
  static char decreaseChar = 'Z'; // Alfabetiskt tecken för att minska insatsen
  // Kontrollera om knappen för att minska insatsen är hög och om villkoren för minskning är uppfyllda
  if (digitalRead(decreaseBetPin) == HIGH && bet >= 10 && millis() - lastDebounceTimeDecrease > debounceDelay && !decreaseButtonPressed) {
    lastDebounceTimeDecrease = millis();
    bet -= 10; // Minska insatsen med 10
    lcd.clear(); // Rensa LCD-skärmen
    // Skriv ut punkter för att skapa en rullande effekt
    for (int i = 0; i < 5; i++) {
      lcd.print(".");
      delay(50); // Justera fördröjningen för rullningshastigheten
    }
    // Skriv ut det aktuella alfabetiska tecknet för att minska insatsen
    lcd.print(decreaseChar);

    // Skapa en rullande effekt för "enheter" på översta raden
    for (int i = 0; i < 5; i++) {
      lcd.print(".");
      delay(50); // Justera fördröjningen för rullningshastigheten
    }

    // Skriv ut information om knappen som tryckts och den aktuella insatsen och tecknet
    Serial.print("Decrease button pressed. Bet: ");
    Serial.print(bet);
    Serial.print(". Current character: ");
    Serial.println(decreaseChar);

    decreaseChar--; // Minska det alfabetiska tecknet för nästa gång
    if (decreaseChar < 'A') {
      decreaseChar = 'Z'; // Återställ till 'Z' om det går under 'A'
    }

    displayBet(); // Uppdatera visningen av insatsen på skärmen
    decreaseButtonPressed = true;

    delay(debounceDelay);
  }
  // Kontrollera om knappen för att minska insatsen är låg och återställ flaggan
  if (digitalRead(decreaseBetPin) == LOW && decreaseButtonPressed) {
    decreaseButtonPressed = false;
  }
}