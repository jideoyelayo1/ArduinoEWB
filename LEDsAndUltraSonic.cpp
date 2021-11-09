/* Below I have attached example code on how to use the LCD */

int HighVal = 25;
int LowVal = 20;

int GreenPin = 1;
int YellowPin = 2;
int RedPin = 3;

#define echoPin 12 // attach pin D12 Arduino to pin Echo of HC-SR04
#define trigPin 13 //attach pin D13 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance_cm; // variable for centimeters measurement
int distance_inch; // variable for inches measurement

void setup() {
    pinMode(GreenPin, OUTPUT);
    pinMode(YellowPin, OUTPUT);
    pinMode(RedPin, OUTPUT);
    
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
    pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
    Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}

void loop() {

    // Clears the trigPin condition
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance_cm = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
    distance_inch = duration * 0.0133 / 2; // Speed of sound wave divided by 2 (go and back)

    if(distance_cm > HighVal)
        digitalWrite(RedPin, HIGH);
    else
        digitalWrite(RedPin, LOW);

    if( LowVal < distance_cm < HighVal)
        digitalWrite(YellowPin, HIGH);
    else
        digitalWrite(YellowPin, LOW);

    if(distance_cm < LowVal)
        digitalWrite(GreenPin, HIGH);
    else
        digitalWrite(GreenPin, LOW);
    delay(500)

}

