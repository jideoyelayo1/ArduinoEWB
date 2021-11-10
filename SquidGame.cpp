#include <stdlib.h>

int ledPin = 13;                // choose the pin for the LED
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int buzzerPin = 10;             // Buzzer pin

bool CanMove,HasLost;

void static detectingMotion(void);


void setup() {
    pinMode(ledPin, OUTPUT);      // declare LED as output
    pinMode(inputPin, INPUT);     // declare sensor as input
    pinMode(buzzerPin, OUTPUT);

    Serial.begin(9600);
}

void loop(){
    val = digitalRead(inputPin);  // read input value
    float num = rand() % 10;
    if(num%2==0) {
        detectingMotion();
        digitalWrite(ledPin,LOW);
    }
    else
        digitalWrite(ledPin,HIGH);

    delay(1000);



}

void static detectingMotion(void){
    if (val == HIGH && CanMove)	// check if the input is HIGH
    {
        digitalWrite(ledPin, HIGH);  // turn LED ON

        if (pirState == LOW)
        {
            Serial.println("Motion detected!");	// print on output change
            pirState = HIGH;
            tone(buzzer, 1000); // Send 1KHz sound signal...
            delay(1000);
            noTone(buzzer);     // Stop sound...

        }
    }
    else
    {
        digitalWrite(ledPin, LOW); // turn LED OFF

        if (pirState == HIGH)
        {
            Serial.println("Motion ended!");	// print on output change
            pirState = LOW;
        }
    }

}
