// Funktion för att låta spelaren mata in sitt namn
void getPlayerName() {
   lcd.clear(); // Rensa LCD-skärmen
  lcd.setCursor(0, 0);
  lcd.print("Whatis YOU NAME:");
  lcd.setCursor(0, 1);

  unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 50;  // Justera debounce-förseningen vid behov
}
