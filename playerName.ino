// Funktion för att låta spelaren mata in sitt namn
void getPlayerName() {
  lcd.clear(); // Rensa LCD-skärmen
  lcd.setCursor(0, 0);
  lcd.print("Whatis YOU NAME:");
  lcd.setCursor(0, 1);

  unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 50;  // Justera debounce-förseningen vid behov

    // Loopa tills spelarens namn har matats in
  while (!nameEntered) {
    // Visa det aktuella namnet och det valda bokstaven utan att rensa skärmen
    lcd.setCursor(0, 1);
    lcd.print(playerName);
    lcd.print(alphabet[currentCharIndex]);

    // Kontrollera knapptryckningar med debounce
    if (millis() - lastDebounceTime > debounceDelay) {
      if (digitalRead(endGamePin) == LOW) {
        playerName += alphabet[currentCharIndex];
        lcd.setCursor(playerName.length(), 1);
        lcd.print(alphabet[(currentCharIndex + 1) % 36]); // Visa nästa bokstav
        lastDebounceTime = millis();
        while (digitalRead(endGamePin) == LOW) {} // Vänta tills knappen släpps
      } else if (digitalRead(playerButtonPin) == LOW) {
        // Om namnet har en längd större än 0, markera att namnet är matat in och visa det välkomnande meddelandet
        if (playerName.length() > 0) {
          nameEntered = true;
          lcd.clear();
          lcd.print("WELCOME, ");
          lcd.print(playerName);
          delay(2000); 
        } else {
          // Om inget namn matats in, visa meddelande och fortsätt loopa för att mata in namnet
          lcd.clear();
          lcd.print("Believe you can:");
          delay(1500);
          lcd.clear();
          lcd.print("ENTER YOUR NAME:");
          lcd.setCursor(0, 1);
          delay(1500);
          continue;
        }
      } else if (digitalRead(increaseBetPin) == LOW) {
        currentCharIndex = (currentCharIndex + 1) % 36;
        lastDebounceTime = millis();
        while (digitalRead(increaseBetPin) == LOW) {} // Vänta tills knappen släpps
      } else if (digitalRead(decreaseBetPin) == LOW) {
        currentCharIndex = (currentCharIndex - 1 + 36) % 36;
        lastDebounceTime = millis();
        while (digitalRead(decreaseBetPin) == LOW) {} // Vänta tills knappen släpps
      }
    }
  }
}
