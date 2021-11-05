//TMP36 Pin Variables
int numBlinks; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade with a
                        //500 mV offset to allow for negative temperatures
 int GreenPin = 1;
 int YellowPin = 2;
 int RedPin = 3;
/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);  //Start the serial connection with the computer
                       //to view the result open the serial monitor 
}
 
void loop()                     // run over and over again
{
Serial.println("How Many Times Do You Want the Red LEDs to blink?"); //Prompt User for Input
  while (Serial.available() == 0) {
    // Wait for User to Input Data
  }
  numBlinks = Serial.parseInt(); //Read the data the user has input

 if(numBlinks == 1) digitalWrite(GreenPin,HIGH);
 else digitalWrite(GreenPin,LOW);
  if(numBlinks == 1) digitalWrite(YellowPin,HIGH);
 else digitalWrite(YellowPin,LOW);
  if(numBlinks == 1) digitalWrite(RedPin,HIGH);
 else digitalWrite(RedPin,LOW);
 delay(2000);
    
  }
 
