void IncreaseBetPress() {
  static bool increaseButtonPressed = false;
  static char increaseChar = 'A'; // Alfabetiskt tecken för att öka insatsen

  // Kontrollera om knappen för att öka insatsen är hög och om villkoren för ökning är uppfyllda
  if (digitalRead(increaseBetPin) == HIGH && (bet + 10) <= playerMoney && millis() - lastDebounceTimeIncrease > debounceDelay && !increaseButtonPressed) {
    lastDebounceTimeIncrease = millis();
    bet += 10; 
    lcd.clear(); 
    // Skriv ut punkter för att skapa en rullande effekt
    for (int i = 0; i < 5; i++) {
      lcd.print(".");
      delay(50); // Justera fördröjningen för rullningshastigheten
    }
    lcd.print(increaseChar); // Visa det aktuella alfabetiska tecknet för att öka insatsen
    // Skriv ut punkter för att skapa en rullande effekt
    for (int i = 0; i < 5; i++) {
      lcd.print(".");
      delay(50); // Justera fördröjningen för rullningshastigheten
    }

    // Skriv ut information om knappen som tryckts och den aktuella insatsen och tecknet
    Serial.print("Increase button pressed. Bet: ");
    Serial.print(bet);
    Serial.print(". Current character: ");
    Serial.println(increaseChar);

    increaseChar++; // Öka alfabetiskt tecken för nästa gång
    if (increaseChar > 'Z') {
      increaseChar = 'A'; // Återgå till 'A' om det överskrider 'Z'
    }

    displayBet(); // Uppdatera visningen av insatsen på skärmen
    increaseButtonPressed = true;

    delay(debounceDelay);
 }
 // Kontrollera om knappen för att öka insatsen är låg och återställ flaggan
  if (digitalRead(increaseBetPin) == LOW && increaseButtonPressed) {
    increaseButtonPressed = false;
 }
}
