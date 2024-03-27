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
  
  int playerRoll = rollDice(); 
  int computerRoll = rollDice(); 
  lcd.clear(); // Rensa LCD-skärmen
  lcd.print("You roll: ");
  lcd.print(playerRoll);
  delay(1000); // Fördröjning för att låta spelaren se deras rullning

  lcd.setCursor(0, 1);
  lcd.print("Computer roll: ");
  lcd.print(computerRoll);
  delay(2000); 

  // Hantera resultatet av tärningsrullningarna
  if (playerRoll > computerRoll) {
    lcd.clear();
    lcd.print("You win!");
    playerMoney += bet;
    wins++;
    digitalWrite(ledWin, HIGH); // Tänd vinnar-LED
    delay(1000);
    digitalWrite(ledWin, LOW); // Stäng av vinnar-LED
  } else if (playerRoll < computerRoll) { // Om spelaren förlorar
    lcd.clear();
    lcd.print("You lose!");
    playerMoney -= bet;
    losses++;
    digitalWrite(ledLose, HIGH); // Tänd förlorar-LED
    delay(1000);
    digitalWrite(ledLose, LOW); // Stäng av förlorar-LED

    if (playerMoney <= 0) { 
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Game over!");
      delay(500);
      lcd.setCursor(0, 1);
      lcd.print("Resetting...");
      delay(500);
      playerMoney = 100; // Återställ spelarens pengar till 100
      lcd.clear();
    }
  } else { // Om det blir oavgjort
    lcd.clear();
    lcd.print("It's a tie!");
  }
  lcd.setCursor(0, 1);
  lcd.print("Your money: $");
  lcd.print(playerMoney);
  delay(3000);
  lcd.clear();
  lcd.print("Choose bet");
  lcd.clear();
  lcd.print("Press roll");
  bet = initialBet; // Återställ satsen till det initiala beloppet

  // Spara vinster och förluster till EEPROM
  EEPROM.write(winsEEPROMAddress, wins);
  EEPROM.write(lossesEEPROMAddress, losses);
}