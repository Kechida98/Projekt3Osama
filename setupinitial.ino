void setup() {
  Serial.begin(9600); // Starta seriekommunikationen med baudrate 9600
  lcd.begin(16, 2);   // Starta LCD-skärmen med dimensionerna 16x2
  pinMode(playerButtonPin, INPUT_PULLUP); // Sätt spelarknappen som en input med intern pull-up resistor
  pinMode(increaseBetPin, INPUT_PULLUP);  // Sätt knappen för att öka satsningen som en input med intern pull-up resistor
  pinMode(decreaseBetPin, INPUT_PULLUP);  // Sätt knappen för att minska satsningen som en input med intern pull-up resistor
  pinMode(endGamePin, INPUT_PULLUP);      // Sätt knappen för att avsluta spelet som en input med intern pull-up resistor
  pinMode(ledWin, OUTPUT);                // Sätt vinnande LED som en output
  pinMode(ledLose, OUTPUT);               // Sätt förlorande LED som en output

  // Anropa funktionen för att få spelarens namn
  getPlayerName();

  // Läs antalet vinster och förluster från EEPROM
  wins = EEPROM.read(winsEEPROMAddress);
  losses = EEPROM.read(lossesEEPROMAddress);

  // Återställ spelets tillstånd
  resetGameState();
}
