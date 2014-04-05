//PWM test
// Vary LED brightness by holding a button

const int LED = 9; //LED on pin 9
const int SW = 7; //switch on pin 7

int brightness = 128;
int val = 0;
int oldVal = 0;
int state = 0;

unsigned long startTime = 0;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(SW, INPUT);
}

void loop(){
  
  val = digitalRead(SW);
  
  if (val == HIGH && oldVal == LOW) {   //detect switch toggle off->on
    state = 1 - state;                  // toggle state
    startTime = millis();               // get time button pressed
    delay(10);
  }
  
  if (val == HIGH && oldVal == HIGH) {                  //detect if button held
    if (state == 1 && (millis() - startTime) > 500) {  // longer than 500ms
      brightness++;                                    //increase brightness
      delay(50);
      if (brightness > 255) brightness = 0;            // range is 0 - 255
    }
  }
  
  oldVal = val;
  
  if (state == 1) analogWrite(LED, brightness);
  else analogWrite(LED, 0);
  
}
