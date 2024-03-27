void EndGamePress() {
  static bool endButtonPressed = false; // Flagga för att spåra om avslutningsknappen trycks

  // Kontrollera om avslutningsknappen är hög och tillräckligt med tid har passerat sedan senaste avtryckningen och om knappen inte redan har tryckts
  if (digitalRead(endGamePin) == HIGH && millis() - lastDebounceTimeEnd > debounceDelay && !endButtonPressed) {
    lastDebounceTimeEnd = millis(); // Uppdatera tiden för senaste avtryckningen
    endButtonPressed = true; // Markera att knappen har tryckts

    lcd.clear(); // Rensa LCD-skärmen

    // Om spelet är aktivt
    if (gameActive) {
      lcd.print("Exiting game"); 
      delay(3000); 
      lcd.clear(); 
      lcd.setCursor(0, 0);
      lcd.print("You left with"); 
      delay(250); 
      lcd.setCursor(0, 1);
      lcd.print("Money = ");
      lcd.print(playerMoney); 
      delay(2000); 
      lcd.clear(); // Rensa LCD-skärmen

      // Skriv ut den viftande texten rad för rad
      for (int i = 0; i < 3; i++) {
        lcd.setCursor(0, 2);
        lcd.print("                "); // Rensa föregående text
        lcd.setCursor(0, 2);
        lcd.print("Game reset"); // Visa meddelandet "Game reset"
        delay(1000); // Vänta i 1 sekund
        lcd.setCursor(0, 3);
        lcd.print("                "); // Rensa föregående text
        lcd.setCursor(0, 3);
        lcd.print("play again!"); // Visa meddelandet "play again!"
        delay(1000); // Vänta i 1 sekund
      }

      resetGameState(); // Återställ spelets tillstånd
      gameActive = false; // Markera att spelet inte längre är aktivt
    } else { // Om spelet inte är aktivt
      if (!gameStarted) { // Om spelet ännu inte har börjat
        lcd.print("Goodluck!"); // Visa meddelandet "Goodluck!"
        delay(2000); 
        lcd.clear(); 
        lcd.setCursor(0, 0);
        lcd.print("Current saldo:"); 
        lcd.setCursor(0, 1);
        lcd.print(playerMoney); 
        delay(3000);
        lcd.clear(); 

        gameStarted = true; // Markera att spelet har börjat
      }

      gameActive = true; // Markera att spelet är aktivt
    }

    displayMain(); 
  } else if (digitalRead(endGamePin) == LOW) { // Om avslutningsknappen är låg
    endButtonPressed = false; // Återställ flaggan för knapptryckning för att avsluta spelet
  }
}