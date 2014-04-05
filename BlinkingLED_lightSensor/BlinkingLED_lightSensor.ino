// Light sensor
//  detecting amount of light using analog input

const int LED = 13;

int val = 0;

void setup(){
  pinMode(LED, OUTPUT);
  
  //no need to set analog input
}

void loop(){
  val = analogRead(0); //read from A0 (light sensor) 
  
  // blink LED with delay equals val
  digitalWrite(LED, HIGH);
  delay(val);
  digitalWrite(LED, LOW);
  delay(val);
  
}
