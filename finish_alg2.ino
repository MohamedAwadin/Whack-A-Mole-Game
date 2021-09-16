/*
  >>>>>>>>>>> Momentum Team's Projects <<<<<<<<<<<< .
   Project Name : Whack - Mole Game
   Software  Team : Mohamed Awadin - Nada Mohamed
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int buzz =7;
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
/* To connect two lcd with only 2 to pin in in arduino UNO ,instead of using 8Pins from arduino for each one .
   We using I2C communication protocol , we need from the arduino only 2PINS (1-Serial data line(PIN A4) && 2-Serial clock line(PIN A5)).
   And to make this process we need to use (PCF8574)IC ,And adjust the fuses of it to adjust the address of each lcd.
*/
LiquidCrystal_I2C lcd1(0x20, 16, 2); // set the LCD address to 0x20 for a 16 chars and 2 line display (LCD 1st player)
LiquidCrystal_I2C lcd2(0x27, 16, 2);// set the LCD address to 0x27(LCD 2nd player)

//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//LEDs pins configertion .
int player1_leds[5] = {2, 3, 4, 5, 6};
int player2_leds[5] = {8, 9, 10, 11, 12};
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//Push Button configertion .
/*
   We make an Hardware connection for each 5 Push buttons for each player .
   This connection make each 5 Push buttons connect with only one analog pin in the arduino .
   This connection make the 5 Push buttons like an rheostat; when you push in any button it give the analog input in the arduino
   values around (0 : 1023).
   Then you can Save the value of each Push in the array with order of the buttons
   ,then you can check the value of each button with it's indeex in the array .
*/
int button_values[] = {913, 429, 267, 179, 110};
int pin_player1 = A0 ;
int pin_player2 = A1 ;
//make a var to save the analog_read for each player .
int analogValue = 0; 
// make a value to correct the error caused by connecting the buttons .
int btn_tol = 20 ;

//$$$$$$$$$$$$$$$$$$$$
long randNum;  
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// Var to calculate score for each player ,
int leds_cnt = 5 ;
int player1_score = 0 ;
int player2_score = 0 ;
//varible to control the time of each push 
int action_speed = 2000 ;
int action_speed_min = 250 ;
int step_counter = 0 ;
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
void setup()
{
  Serial.begin(9600);
  //we Use randomseed() function to give us an random and varible value for each player.
  randomSeed(analogRead(A2)); 
  //Initialize two lcd .
  lcd1.init(); // initialize first player's lcd
  lcd2.init(); // initialize second player's lcd
  lcd1.backlight();
  lcd2.backlight();

  //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  //config for all pins in the code according to there jobs.
  pinMode(pin_player1, INPUT);//input of the of the pushButtons of the first player
  pinMode(pin_player2, INPUT);//input of the of the pushButtons of the second player
  pinMode(buzz, OUTPUT); // Output of the buzzer's finish game.

  for (int i = 0 ; leds_cnt > i ; i++)// for loop to make all the led's pins for the first player as output pins
  {
    pinMode(player1_leds[i], OUTPUT);
  }
  for (int i = 0 ; leds_cnt > i ; i++)// for loop to make all the led's pins for the second player as output pins
  {
    pinMode(player2_leds[i], OUTPUT);
  }
  //$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
  //LCD prepare to get started in the game ;
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("PLAYER1:");
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("PLAYER2:"); //2.2379
 
}


void loop()
{
  if ((player1_score < 100) && (player2_score < 100))
  {
   step_counter++;
   bool step_action = false ;
   if (step_counter > action_speed) 
   {
      step_counter = 0 ;
      step_action = true ;
      action_speed = action_speed - round(action_speed / 50);
      if (action_speed < action_speed_min) {
        action_speed = action_speed_min  ;
      }
      Serial.print("       s=");
      Serial.println(action_speed);
    }
    if (step_action) 
    {
      int pin_light = random(0, 5);
      digitalWrite(player1_leds[pin_light], HIGH);
      digitalWrite(player2_leds[pin_light], HIGH);;
    }
    analogValue = analogRead(pin_player1);
    for (int i = 0; leds_cnt > i ; i++) {
      if ( (analogValue < button_values[i] + btn_tol) && (analogValue > button_values[i] - btn_tol) ) {
        if (digitalRead(player1_leds[i]) == HIGH) {
          digitalWrite(player1_leds[i], LOW);
          player1_score++;
        }
      }
    }
    analogValue = analogRead(pin_player2);
    for (int i = 0; leds_cnt > i ; i++) {
      if ( (analogValue < button_values[i] + btn_tol) && (analogValue > button_values[i] - btn_tol) ) {
        if (digitalRead(player2_leds[i]) == HIGH) {
          digitalWrite(player2_leds[i], LOW);
          player2_score++;
        }
      }
    }
    if (step_counter % 100 == 0 ) {
      lcd1.setCursor(0, 1);
      lcd1.print(player1_score);
      lcd2.setCursor(0, 1);
      lcd2.print(player2_score);
    }
  }
  else {
    if (player1_score > player2_score) {
      lcd1.setCursor(8, 0);
      lcd1.print("WINNER");
      lcd2.setCursor(8, 0);
      lcd2.print("LOSSER");
      for(int i =2 ; i<=6 ; i++)
      {
        delay(200);
        digitalWrite(i,HIGH);
        digitalWrite(buzz,HIGH);
        digitalWrite(8,HIGH);
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);
        digitalWrite(11,HIGH);
        digitalWrite(12,HIGH);
        delay(500);
        digitalWrite(i,LOW);
        digitalWrite(buzz,LOW);
        digitalWrite(8,LOW);
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(11,LOW);
        digitalWrite(12,LOW);
        
        }

    } 
    else {
      lcd2.setCursor(8, 0);
      lcd2.print("WINNER");
      lcd1.setCursor(8, 0);
      lcd1.print("LOSSER");
      for(int i =8 ; i<=12 ; i++)
      {
        delay(200);
        digitalWrite(i,HIGH);
        digitalWrite(buzz,HIGH);
        digitalWrite(2,HIGH);
        digitalWrite(3,HIGH);
        digitalWrite(4,HIGH);
        digitalWrite(5,HIGH);
        digitalWrite(6,HIGH);
        delay(500);
        digitalWrite(i,LOW);
        digitalWrite(buzz,LOW);
        digitalWrite(2,LOW);
        digitalWrite(3,LOW);
        digitalWrite(4,LOW);
        digitalWrite(5,LOW);
        digitalWrite(6,LOW);
        
        }

    }
  }
  
}
