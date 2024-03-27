// Läs antalet vinster och förluster från EEPROM
  wins = EEPROM.read(winsEEPROMAddress);
  losses = EEPROM.read(lossesEEPROMAddress);