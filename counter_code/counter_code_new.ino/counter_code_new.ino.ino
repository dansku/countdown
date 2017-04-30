/*

  Days Countdown
  Daniel Andrade _ www.danielandrade.net
  2017

  Code To Display Countdown to a specific date

*/

#include <math.h>

// Serial2Parallel Pins
const uint8_t latchPin   = 8;
const uint8_t dataPin   = 11;
const uint8_t clockPin  = 13;

const uint8_t segPins[7] = {2, 3, 4, 5, 6, 7, 9};

const uint8_t zero[7]   = {1, 1, 1, 1, 1, 1, 0};
const uint8_t one[7]    = {0, 1, 1, 0, 0, 0, 0};
const uint8_t two[7]    = {1, 1, 0, 1, 1, 0, 1};
const uint8_t three[7]  = {1, 1, 1, 1, 0, 0, 1};
const uint8_t four[7]   = {0, 1, 1, 0, 0, 1, 1};
const uint8_t five[7]   = {1, 0, 1, 1, 0, 1, 1};
const uint8_t six[7]    = {1, 0, 1, 1, 1, 1, 1};
const uint8_t seven[7]  = {1, 1, 1, 0, 0, 0, 0};
const uint8_t eight[7]  = {1, 1, 1, 1, 1, 1, 1};
const uint8_t nine[7]   = {1, 1, 1, 1, 0, 1, 1};

uint8_t dayBuffer[3] ; 
uint8_t hourBuffer[2] ; 
uint8_t minuteBuffer[2] ; 
uint8_t secondBuffer[2] ; 

// Final date of the countdown in seconds from https://www.epochconverter.com/
const uint32_t final_date = 1517486400; 

void lightLeds (int second, int first) {
  digitalWrite (latchPin, LOW);
  shiftOut (dataPin, clockPin, LSBFIRST, first);
  shiftOut (dataPin, clockPin, LSBFIRST, second);
  digitalWrite (latchPin, HIGH);
 // delay (1);
}

void displayNumber(int num)
{
    switch (num) { // normal int
    case 1: 
      SetONE();
      break;

    case 2:
      SetTWO();
      break;

    case 3: 
      SetTHREE();
      break;
    case 4:
      SetFOUR();
      break;

    case 5:
      SetFIVE();
      break;

    case 6:
      SetSIX();
      break;

    case 7:
      SetSEVEN();
      break;    

    case 8:
      SetEIGHTH();
      break;

    case 9:
      SetNINE();
      break;  

    case 0:
      SetZERO();
      break;

    default: 
      SetOFF();
      break;
  }
  delay(1);
  SetOFF();
}

void SetOFF()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], LOW);
  }
}

void SetZERO() 
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], zero[i]);
  }
}

void SetONE()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], one[i]);
  }
}

void SetTWO()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], two[i]);
  }
}

void SetTHREE()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], three[i]);
  }
}

void SetFOUR()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], four[i]);
  }
}

void SetFIVE()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], five[i]);
  }
}

void SetSIX()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], six[i]);
  }
}

void SetSEVEN()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], seven[i]);
  }
}

void SetEIGHTH()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], eight[i]);
  }
}

void SetNINE()
{
  for (int i = 0; i < 7; i++)
  {
    digitalWrite(segPins[i], nine[i]);
  }
}


unsigned long lastTime = 0;
unsigned long UpdateDelay = 1000;

void setup() {
  pinMode (dataPin, OUTPUT);
  pinMode (clockPin, OUTPUT);
  pinMode (latchPin, OUTPUT);

  for (int i = 0; i <= 8; i++) {
    pinMode(segPins[i], OUTPUT);
  }
  Serial.begin(9600);
  Serial.println("System Starting");

  //INIT ALL OFF
  SetOFF();
  lightLeds (0b00000000, 0b00000000);
  delay(1000);
}


uint32_t current_epoch_time = 1493588851;

void loop() {

    if(millis() - lastTime >= UpdateDelay)
    {

        lastTime = millis();

        // DateTime now     = RTC.now();                  //get the current date-time
        // current_epoch_time   = (now.get());                //seconds
        
        uint32_t difference = final_date - current_epoch_time;

        uint32_t days     = floor(difference / 86400);
        uint32_t hours    = floor((difference - (days * 86400))/(3600));
        uint32_t minutes  = floor((difference - (days * 86400) - (hours * 3600))/60);
        uint32_t seconds  = floor(difference -  (days * 86400) - (hours * 3600) - (minutes * 60));

        // Split Numbers into array
        dayBuffer[2] = days % 10;
        dayBuffer[1] = (days / 10) % 10;
        dayBuffer[0] = (days / 100) % 10;

        hourBuffer[1] = hours % 10;
        hourBuffer[0] = (hours / 10) % 10;

        minuteBuffer[1] = minutes % 10;
        minuteBuffer[0] = (minutes / 10) % 10;

        secondBuffer[1] = seconds % 10;
        secondBuffer[0] = (seconds / 10) % 10;

        current_epoch_time++;

    }




    
    lightLeds (0b10000000, 0b00000000);
    displayNumber(dayBuffer[0]);

    lightLeds (0b01000000, 0b00000000);
    displayNumber(dayBuffer[1]);

    lightLeds (0b00100000, 0b00000000);
    displayNumber(dayBuffer[2]);



    lightLeds (0b00010000, 0b00000000);
    displayNumber(hourBuffer[0]);

    lightLeds (0b00001000, 0b00000000);
    displayNumber(hourBuffer[1]);



    lightLeds (0b00000100, 0b00000000);
    displayNumber(minuteBuffer[0]);

    lightLeds (0b00000010, 0b00000000);
    displayNumber(minuteBuffer[1]);



    lightLeds (0b00000001, 0b00000000);
    displayNumber(secondBuffer[0]);

    lightLeds (0b00000000, 0b11111111);
    displayNumber(secondBuffer[1]);


}



