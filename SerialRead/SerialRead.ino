// reading LDR value from analog in

const int SENSOR = 0; // sensor at analog in 0

int val = 0;

void setup(){
  Serial.begin(9600); //start serial com at 9600 baud
  
}

void loop(){
 val = analogRead(SENSOR);
 
 Serial.println(val);
 
 delay(100);
  
}
