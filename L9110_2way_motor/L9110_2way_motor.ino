// L9110 H-bridge 2-way motor test
// Pin: INA: 8, INB: 7

#define inA 9
#define inB 6

void setup()
{
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
}

void loop()
{
  static int i = 100;
  
  analogWrite(inA, 40);
  analogWrite(inB, 0);
  
}
