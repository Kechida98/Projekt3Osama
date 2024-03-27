// Funktion för att visa det aktuella tecknet för spelarens namn
void displayCurrentChar() {
  lcd.clear(); // Rensa LCD-skärmen
  lcd.setCursor(0, 0);
  lcd.print("ENTER YOUR NAME:");
  lcd.setCursor(0, 1);
  lcd.print(playerName);
  lcd.print(alphabet[currentCharIndex]);
  
}