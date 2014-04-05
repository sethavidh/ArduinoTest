// Ultrasonic range test, just get range in CM

const int trigPin = 8;
const int echoPin = 11;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

void loop(){
  unsigned int duration = 0;
  //trigger high signal for 10 microsecs on trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(4);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //read from echo pin
  duration = pulseIn(echoPin, HIGH);
  Serial.print("distance = ");
  Serial.println(duration/58);
  delay(1000);
}
