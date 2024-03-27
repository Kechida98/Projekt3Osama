void rollDiceAndHandleResult() {
  lcd.clear(); // Rensa LCD-skärmen
  lcd.print("Choose bet"); // Visa meddelande för att välja sats
  lcd.setCursor(0, 1);
  lcd.print("Current bet: ");
  lcd.print(bet); // Visa det aktuella satsbeloppet
  
  // Loop för att hantera knapptryckningar medan spelarknappen är nedtryckt
  while (digitalRead(playerButtonPin) == HIGH) {
    EndGamePress(); // Hantera knapptryckning för att avsluta spelet
    IncreaseBetPress(); // Hantera knapptryckning för att öka satsningen
    DecreaseBetPress(); // Hantera knapptryckning för att minska satsningen
  }
}