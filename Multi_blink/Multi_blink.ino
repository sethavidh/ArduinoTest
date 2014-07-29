// Multi-blink test
// Pin: 2,3,4 On when LOW

// define LED time to stay on/off in ms
#define fastOn 100
#define fastOff 100
#define medOn 300
#define medOff 300
#define slowOn 700
#define slowOff 700

typedef struct {
  int state;
  int lastChange;
  int onRate;
  int offRate;
  int pin;
} LED;

LED one, two, three;
void setup()
{
   int t = millis();
   
   one.state = HIGH;
   one.onRate = fastOn;
   one.offRate = fastOff;
   one.lastChange = t;   
   one.pin = 2;

   two.state = HIGH;
   two.onRate = medOn;
   two.offRate = medOff;
   two.lastChange = t;
   two.pin = 3;

   three.state = HIGH;
   three.onRate = slowOn;
   three.offRate = slowOff;
   three.lastChange = t;
   three.pin = 4;
   
   pinMode(one.pin, OUTPUT); 
   pinMode(two.pin, OUTPUT); 
   pinMode(three.pin, OUTPUT); 
}

void loop()
{
   int t;
   t = millis();
   
   if (t - one.lastChange > one.onRate) {
     one.state = 1 - one.state;
     one.lastChange = t;
   }
   
   if (t - two.lastChange > two.onRate) {
     two.state = 1 - two.state;
     two.lastChange = t;
   }
   
   if (t - three.lastChange > three.onRate) {
     three.state = 1 - three.state;
     three.lastChange = t;
   }

   digitalWrite(one.pin, one.state);
   digitalWrite(two.pin, two.state);
   digitalWrite(three.pin, three.state);
}
