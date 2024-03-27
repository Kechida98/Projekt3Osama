// Adresser för att lagra antal vinster och förluster i EEPROM
const int winsEEPROMAddress = 0;
const int lossesEEPROMAddress = 1;

//Definera stift för olika knappar och lysdioder
const int playerButtonPin = A0;    
const int increaseBetPin = 4;     
const int decreaseBetPin = 5;     
const int endGamePin = 3;         
const int ledWin = 6;             
const int ledLose = 13;          

// Initiala variabler
int playerMoney = 100;            
int initialBet = 0;               
int bet = initialBet;             
int wins = 0;                     
int losses = 0;

//booleans för knapptryck och spelstatus                 
bool canBet = true;               
bool gameActive = false;          
bool gameStarted = false;         
bool endingGame = false;         
bool nameEntered = false;         

String playerName = "";           // Spelarens namn
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; // Alfabetet och siffrorna som används för namnet
int currentCharIndex = 0;         // Index för det aktuella tecknet i alfabetet

//kollar senast tidpunk då knappen trycktes,öka,minska,avlusta
unsigned long lastDebounceTimePlayer = 0;   
unsigned long lastDebounceTimeIncrease = 0; 
unsigned long lastDebounceTimeDecrease = 0; 
unsigned long lastDebounceTimeEnd = 0;      
unsigned long debounceDelay = 50;           // Debounce-försening