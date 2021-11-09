#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int ledPin = 13;                // choose the pin for the LED
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

void setup() {

    lcd.begin(16, 2); // we are having a 16 across and 2 down LCD
    pinMode(ledPin, OUTPUT);      // declare LED as output
    pinMode(inputPin, INPUT);     // declare sensor as input

    Serial.begin(9600);
}

void loop(){
    val = digitalRead(inputPin);  // read input value
    lcd.clear();

    if (val == HIGH)	// check if the input is HIGH
    {
        digitalWrite(ledPin, HIGH);  // turn LED ON

        if (pirState == LOW)
        {

            lcd.setCursor(0,0); // start writing from 0,0
            lcd.print("Motion detected!");	// print on output change
            pirState = HIGH;
        }
    }
    else
    {
        digitalWrite(ledPin, LOW); // turn LED OFF

        if (pirState == HIGH)
        {

            lcd.setCursor(0,0); // start writing from 0,0
            lcd.println("Motion ended!");	// print on output change
            pirState = LOW;
        }
    }
    delay(200);
}
