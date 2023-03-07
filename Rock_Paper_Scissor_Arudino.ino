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

// Pins of Buttons for selecting Rock,Paper or Scissors
const int rPlayer = 9;
const int pPlayer = 10;
const int sPlayer = 11;

// Pins of Leds for showing the player's selected option
const int rPlayerLed = 2;
const int pPlayerLed = 3;
const int sPlayerLed = 4;

// Pins of Leds for showing arduino's selected option
const int rArduinoLed = 7;
const int pArduinoLed = 6;
const int sArduinoLed = 5;

int PlayerScore = 0;
int ArduinoScore = 0;

int ArduinoChoice = 0;
int PlayerChoice = 0;
int GameState = 0;

// Pins for the reset and speaker components
int resetBtn = 12;
Music Music(8);

// Setup Function for arduino
void setup() {
  Serial.begin(9600);

  // Setting a whole array of pins as Output or Input (reduces redundant code)
  int inputPins [] = {9,10,11,12};
  int iPinCount = 4;
  int outputPins [] = {2,3,4,5,6,7};
  int oPinCount = 6;

  // Loops for setting the mode of each pin
  for(int i=0;i<=iPinCount;i++){pinMode(inputPins[i],INPUT_PULLUP);};
  for(int i=0;i<=oPinCount;i++){pinMode(outputPins[i],OUTPUT);};

};


void select_player_opt() {
    if (digitalRead(rPlayer)==LOW){
    PlayerChoice = 1;
    digitalWrite(rPlayerLed,HIGH);
    digitalWrite(pPlayerLed,LOW);
    digitalWrite(sPlayerLed,LOW);
  };

  if (digitalRead(pPlayer)==LOW){
    PlayerChoice = 2;
    digitalWrite(rPlayerLed,LOW);
    digitalWrite(pPlayerLed,HIGH);
    digitalWrite(sPlayerLed,LOW);
  };

  if (digitalRead(sPlayer)==LOW){
    PlayerChoice = 3;
    digitalWrite(rPlayerLed,LOW);
    digitalWrite(pPlayerLed,LOW);
    digitalWrite(sPlayerLed,HIGH);
  };
};

void select_aru_opt(){
  if (ArduinoChoice == 1){
    digitalWrite(rArduinoLed,HIGH);
    digitalWrite(pArduinoLed,LOW);
    digitalWrite(sArduinoLed,LOW);
  };

  if (ArduinoChoice == 2){
    digitalWrite(rArduinoLed,LOW);
    digitalWrite(pArduinoLed,HIGH);
    digitalWrite(sArduinoLed,LOW);
  };

  if (ArduinoChoice == 3){
    digitalWrite(rArduinoLed,LOW);
    digitalWrite(pArduinoLed,LOW);
    digitalWrite(sArduinoLed,HIGH);
  };
}

void loop() {

  while (GameState == 1) {
    do {select_player_opt();}while (PlayerChoice == 0);
    ArduinoChoice = random(1,4);    
    select_aru_opt();
    GameState = 2;
    if (digitalRead(resetBtn)==LOW){
      GameState = 0;
      PlayerChoice = 0;
      ArduinoChoice = 0;
      digitalWrite(rPlayerLed,LOW);
      digitalWrite(pPlayerLed,LOW);
      digitalWrite(sPlayerLed,LOW);    
      
      digitalWrite(rArduinoLed,LOW);
      digitalWrite(pArduinoLed,LOW);
      digitalWrite(sArduinoLed,LOW);
    };
  }

  while (GameState == 0) {
    if (digitalRead(resetBtn)==LOW){
      GameState = 1;
      PlayerChoice = 0;
      ArduinoChoice = 0;
      digitalWrite(rPlayerLed,LOW);
      digitalWrite(pPlayerLed,LOW);
      digitalWrite(sPlayerLed,LOW);    

      digitalWrite(rArduinoLed,LOW);
      digitalWrite(pArduinoLed,LOW);
      digitalWrite(sArduinoLed,LOW);
    };
  };

  while (GameState == 2) {
// r 1 p 2 s 3
    if (PlayerChoice == 1 && ArduinoChoice == 1){Music.draw();};
    if (PlayerChoice == 1 && ArduinoChoice == 2){Music.lose();};
    if (PlayerChoice == 1 && ArduinoChoice == 3){PlayerScore++;Music.win();};
    if (PlayerChoice == 2 && ArduinoChoice == 1){PlayerScore++;Music.win();};
    if (PlayerChoice == 2 && ArduinoChoice == 2){Music.draw();};
    if (PlayerChoice == 2 && ArduinoChoice == 3){ArduinoScore++;Music.lose();};
    if (PlayerChoice == 3 && ArduinoChoice == 1){ArduinoScore++;Music.lose();};
    if (PlayerChoice == 3 && ArduinoChoice == 2){PlayerScore++;Music.win();};
    if (PlayerChoice == 3 && ArduinoChoice == 3){Music.draw();};
    Serial.print(PlayerScore);
    Serial.print(ArduinoScore);
    GameState = 0;    
    };
};

// Made with Love by Denzven 💜