 
int ledPin = 13;                // LED 
int pirPin = 2;                 // PIR Out pin 
int pirStat = 0;                   // PIR status
int buttonPin = 8;
bool LastStateWasOn = false;
void setup() {
  pinMode(ledPin, OUTPUT);     
  pinMode(buttonPin, OUTPUT); 
  pinMode(pirPin, INPUT);     
 
  Serial.begin(9600);
}
 
void loop(){
  
  pirStat = digitalRead(pirPin); Serial.println(pirPin);
   
  if (pirStat == HIGH) {            // if motion detected
    digitalWrite(ledPin, HIGH);  // turn LED ON
    //Serial.println("Hey I got you!!!");
    if(LastStateWasOn){
      digitalWrite(buttonPin,HIGH);
      }
      LastStateWasOn = true;
      
      

  } 
  else {
    Serial.println("You didnt move");
    LastStateWasOn = false;
    digitalWrite(ledPin, LOW); // turn LED OFF if we have no motion
      digitalWrite(buttonPin,LOW);
   
  }delay(100);
}
