// Funktion för att hantera spelarens rullknapp
void PlayerRoll() {
  // Kontrollera om spelaren har tryckt på rullknappen och har tillräckligt med pengar och undvik skakningar
  if (digitalRead(playerButtonPin) == HIGH && playerMoney > 0 && millis() - lastDebounceTimePlayer > debounceDelay) {
    lastDebounceTimePlayer = millis(); // Uppdatera tiden för senaste knapptryckning

    lcd.clear(); 
    lcd.print("Press to roll"); 

    // Vänta tills spelaren släpper knappen för att rulla tärningarna
    while (digitalRead(playerButtonPin) == LOW);
 } 
} 