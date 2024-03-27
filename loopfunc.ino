void loop() {
  // Kontrollera om spelarens namn har angetts
  if (!nameEntered) {
    getPlayerName(); // Anropa funktionen för att få spelarens namn
    return;
  }
}