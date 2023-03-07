/* */

// Simple Rock,Paper,Scissors Game with leds,buzzer and btns

/* 
  /----------------------------\
  | * Schematic circuit list * |
  |----------------------------|
  |     Pin 0 <--|--> Led 0    |
  |     Pin 0 <--|--> Led 0    |
  |     Pin 0 <--|--> Led 0    |
  |     Pin 0 <--|--> Led 0    |
  \----------------------------/
*/

// files for objects
#include "Music.h"
#include "LED.h"
#include "Btn.h"

// ----------------------------------------

// Objects for Buttons for selecting Rock,Paper or Scissors (see Btn.cpp for definition)
Btn rPlayerBtn(9);
Btn pPlayerBtn(10);
Btn sPlayerBtn(11);

// Object for Reset Btn
Btn resetBtn(12);

// Objects for Leds for showing the player's selected option (see LED.cpp for definiton)
LED rPlayerLED(2);
LED pPlayerLED(3);
LED sPlayerLED(4);

// Objects of Leds for showing arduino's selected option
LED rArduinoLED(7);
LED pArduinoLED(6);
LED sArduinoLED(5);

// Objects for Buzzer for playing Music (see Music.cpp for definition)
Music Music(8);

// ----------------------------------------

// Game Variables -->

  // 1) Keeps scores
  int PlayerScore = 0;
  int ArduinoScore = 0;

  // 2) Selects Option (1=rock,2=paper,3=scissors,0=undefined)
  int ArduinoChoice = 0;
  int PlayerChoice = 0;

  // 3) sets Game's state (essential for using loop func)
  int GameState = 0;

// ----------------------------------------

// Setup Function for arduino
void setup() {
  // to see printed results in monitor (Optional mostly for debugging)
  Serial.begin(9600);
};

// Reset Function to game state 
// Allows to off all leds and reset choices to start new game
void reset(int gs){
if (resetBtn.press()){
    GameState = gs;
    PlayerChoice = 0;
    ArduinoChoice = 0;

    Serial.println("*---Reset----*");

    rPlayerLED.Off();    
    pPlayerLED.Off();    
    sPlayerLED.Off();    
    rArduinoLED.Off();    
    pArduinoLED.Off();    
    sArduinoLED.Off();
  };
};

// Function to turn on Leds according to selected Btn by Player
void select_player_opt() {
  if (rPlayerBtn.press()){PlayerChoice = 1;rPlayerLED.On();};
  if (pPlayerBtn.press()){PlayerChoice = 2;pPlayerLED.On();};
  if (sPlayerBtn.press()){PlayerChoice = 3;sPlayerLED.On();};
};

// Function to turn on Leds according to selected option by Arduino
void select_aru_opt(){
  if (ArduinoChoice == 1){rArduinoLED.On();};
  if (ArduinoChoice == 2){pArduinoLED.On();};
  if (ArduinoChoice == 3){sArduinoLED.On();};
}

// Main Looping Function (Arduino's default)
void loop() {

  // Idle state (new game starts)
  while (GameState == 0) {
    reset(1);
  };

  // selecting Options (Ongoing Game)
  while (GameState == 1) {
    // wait until player selects option
    do {select_player_opt();}while (PlayerChoice == 0);

    // select random choice and turn on led
    ArduinoChoice = random(1,4);    
    select_aru_opt();

    // proceed to next state (matching)
    GameState = 2;

    //reset to newgame
    reset(0);
  }

  // Matching and scoring
  while (GameState == 2) {
    // Choices ==> 1=Rock,2=Paper,3=Scissors
    // Appropriate Music plays for the scores
    if (PlayerChoice == 1 && ArduinoChoice == 1){Music.draw();};
    if (PlayerChoice == 1 && ArduinoChoice == 2){ArduinoScore++;Music.lose();};
    if (PlayerChoice == 1 && ArduinoChoice == 3){PlayerScore++;Music.win();};
    if (PlayerChoice == 2 && ArduinoChoice == 1){PlayerScore++;Music.win();};
    if (PlayerChoice == 2 && ArduinoChoice == 2){Music.draw();};
    if (PlayerChoice == 2 && ArduinoChoice == 3){ArduinoScore++;Music.lose();};
    if (PlayerChoice == 3 && ArduinoChoice == 1){ArduinoScore++;Music.lose();};
    if (PlayerChoice == 3 && ArduinoChoice == 2){PlayerScore++;Music.win();};
    if (PlayerChoice == 3 && ArduinoChoice == 3){Music.draw();};

    //Pretty print scores
    Serial.println("----Scores----");
    Serial.println("|  p  |  a  |");
    Serial.print("|  ");
    Serial.print(PlayerScore);
    Serial.print("  |  ");
    Serial.print(ArduinoScore);
    Serial.print("  |\n");
    Serial.println("--------------");

    //reset to newgame
    GameState = 0;    
    };
};

// Made with Love by Denzven 💜