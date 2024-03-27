pinMode(playerButtonPin, INPUT_PULLUP); // Sätt spelarknappen som en input med intern pull-up resistor
  pinMode(increaseBetPin, INPUT_PULLUP);  // Sätt knappen för att öka satsningen som en input med intern pull-up resistor
  pinMode(decreaseBetPin, INPUT_PULLUP);  // Sätt knappen för att minska satsningen som en input med intern pull-up resistor
  pinMode(endGamePin, INPUT_PULLUP);      // Sätt knappen för att avsluta spelet som en input med intern pull-up resistor
  pinMode(ledWin, OUTPUT);                // Sätt vinnande LED som en output
  pinMode(ledLose, OUTPUT);               // Sätt förlorande LED som en output