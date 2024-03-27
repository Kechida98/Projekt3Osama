void loop() {
  // Kontrollera om spelarens namn har angetts
  if (!nameEntered) {
    getPlayerName(); // Anropa funktionen för att få spelarens namn
    return;
  }

  // Kontrollera om spelaren kan satsa och spelet är aktivt
  if (canBet && gameActive) {
    EndGamePress();     // Hantera knapptryckning för att avsluta spelet
    IncreaseBetPress(); // Hantera knapptryckning för att öka satsningen
    DecreaseBetPress(); // Hantera knapptryckning för att minska satsningen
  }
  PlayerRoll(); // Hantera spelarens rullknapp
}