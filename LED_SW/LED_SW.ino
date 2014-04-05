// turn LED on/off using switch

const int LED = 13;
const int SW = 7;

int val = 0;
int oldVal = 0;
int state = 0;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
}

void loop(){
  val = digitalRead(SW);
  
  if (val == HIGH && oldVal == LOW) state = 1 - state;
  
  oldVal = val;
  
  if (state == 1) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
  
}
