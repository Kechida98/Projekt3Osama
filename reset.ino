// Funktion för att återställa spelets tillstånd
void resetGameState() {
  playerMoney = 100; 
  gameActive = false; // Markera att spelet inte är aktivt
  canBet = false; // Markera att satsning inte är möjlig
}