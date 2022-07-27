#include <Adafruit_NeoPixel.h>

const int DIN_PIN = 23;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(1,DIN_PIN,NEO_GRB+NEO_KHZ800);

int count = -1;

//RGB Brightness
unsigned char red = 0;
unsigned char green = 0;
unsigned char blue = 0;

void setup()
{
  // put your setup code here, to run once:
  pinMode(24, INPUT_PULLUP);
  pinMode(25,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.print("Count:");
  Serial.println(count);
  if(digitalRead(24) == LOW) {
    count = count + 1;
    Serial.print("Count: ");
    Serial.println(count);
    delay(100);
    if (count == 1) {
      while (digitalRead(24)== LOW) {
        delay(20);
        red++;
        Serial.println(red);
      }
    }
    if (count == 2) {
      while (digitalRead(24)== LOW) {
        delay(20);
        green++;
        Serial.println(green);
      }
    }
    if (count == 3) {
      while (digitalRead(24)== LOW) {
        delay(20);
        blue++;
        Serial.println(blue);
      }
    }
    if (count > 3) {
      count = -1;
      red = 0;
      green = 0;
      blue = 0;
    }else{
      while (digitalRead(24) == LOW) 
      {
        delay(100);
      }
      
    }
  }
  pixels.setPixelColor(0,pixels.Color(red,green,blue));
  pixels.show();
}