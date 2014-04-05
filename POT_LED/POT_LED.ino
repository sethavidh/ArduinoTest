// vary LED by potentiometer

const int POT = 0; //potentiometer at analog 0
const int LED = 9; // LED at pin 9

int val = 0;

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  val = analogRead(POT);
  
  analogWrite(LED, val/4);
}
