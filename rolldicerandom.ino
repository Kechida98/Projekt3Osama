// Funktion för att simulera att tärningen rullas
int rollDice() {
  static bool seeded = false;

  if (!seeded) {
    randomSeed(analogRead(0)); // Använd ett analogt pin-värde som frö
    seeded = true;
  }

  return random(1, 7); // Returnera ett slumpmässigt tal mellan 1 och 6
}