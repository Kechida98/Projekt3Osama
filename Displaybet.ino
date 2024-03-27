// Funktion för att visa den aktuella satsningen
void displayBet() {
  lcd.setCursor(0, 1);
  lcd.print("Current bet: ");
  lcd.print(bet);
}