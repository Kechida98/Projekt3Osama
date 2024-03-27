void rollDiceAndHandleResult() {
  lcd.clear(); // Rensa LCD-skärmen
  lcd.print("Choose bet"); // Visa meddelande för att välja sats
  lcd.setCursor(0, 1);
  lcd.print("Current bet: ");
  lcd.print(bet); // Visa det aktuella satsbeloppet
}