/* Below I have attached example code on how to use the LCD */
#include <OneWire.h>

// Setting up Temp sensor
int AnaloguePin = A0;
int HighVal = 25;
int LowVal = 20;

int GreenPin = 1;
int YellowPin = 2;
int RedPin = 3;

void setup() {
    pinMode(GreenPin, OUTPUT);
    pinMode(YellowPin, OUTPUT);
    pinMode(RedPin, OUTPUT);
}

void loop() {
    int readVal=analogRead(AnaloguePin); // Reads analogue pin
    float temp = Thermistor(readVal);

    if(temp > HighVal)
        digitalWrite(RedPin, HIGH);
    else
        digitalWrite(RedPin, LOW);
    
    if( LowVal < temp < HighVal)
        digitalWrite(YellowPin, HIGH);
    else
        digitalWrite(YellowPin, LOW);
    
    if(temp < LowVal)
        digitalWrite(GreenPin, HIGH);
    else
        digitalWrite(GreenPin, LOW);
    delay(500)



}

//Function that converts Volts into Temperature
double Thermistor(int RawADC) {
    double Temp;
    Temp = log(10000.0*((1024.0/RawADC-1)));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
    Temp = Temp - 273.15;            // Convert Kelvin to Celcius
    return Temp;
}
