/* Below I have attached example code on how to print Temp to LCD */
#include <LiquidCrystal.h>
#include <OneWire.h>

// Setting up Temp sensor
int AnaloguePin = A0;

//Setting up LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Equation found on line to calc temperature based on voltage


void setup() {
    lcd.begin(16, 2); // we are having a 16 across and 2 down LCD

}

void loop() {
    lcd.clear();

    int readVal=analogRead(AnaloguePin); // Reads analogue pin
    
    lcd.setCursor(0,0); // start writing from 0,0
    lcd.print("Temperature  = ");
    
    lcd.setCursor(0,1); // start writing from 0,1
    lcd.print(Thermistor(readVal)); // prints temperature
    
    delay(1000); // waits one second

}

//Function that converts Volts into Temperature
double Thermistor(int RawADC) {
    double Temp;
    Temp = log(10000.0*((1024.0/RawADC-1)));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
    Temp = Temp - 273.15;            // Convert Kelvin to Celcius
    return Temp;
}
