int buzzer = 9; //buzzer to pin 9


void setup(){
 
  pinMode(buzzer, OUTPUT);

}

void loop(){
 
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);
  noTone(buzzer);     // Stop sound...
  delay(1000);
  
}
