// 7-segment 4-digit with 74HC595
//
// wiring: q1=a, q2=b, q3=c, q4=d, q5=e, q6=f, q7=g
// arduino: 7 = ds, 9=latch, 11=clock
//          3=12(digit3), 4=9(digit2), 5=digit1, 6=digit0
//

const int ds=7, latch=9, clock=11;
const int d0=6,d1=5,d2=4,d3=3;

void setup(){
  pinMode(ds, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(d0, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
}

void loop(){
  int i = 0;
  byte data;

  displayNum4(6789);
  
}
void displayNum4(int num){
  int c0,c1,c2,c3;
  
  //separate digits
  c0 = num%10;
  num = num/10;
  c1 = num%10;
  num = num/10;
  c2 = num%10;
  c3 = num/10;
  
  //don't display leading 0
  if (c3 == 0) numOff();
  else displayNum(c3);   
  digitalWrite(d3,LOW);
  digitalWrite(d3,HIGH);
  numOff();              //reset
  if (c3 == 0 && c2 == 0) numOff();
  else displayNum(c2);
  digitalWrite(d2,LOW);
  digitalWrite(d2,HIGH);
  numOff();
  if (c3 == 0 && c2 == 0 && c1 == 0) numOff();
  else displayNum(c1);
  digitalWrite(d1,LOW);
  digitalWrite(d1,HIGH);
  numOff();
  //display last digit even if it's 0
  displayNum(c0);
  digitalWrite(d0,LOW);
  digitalWrite(d0,HIGH);
  numOff();
}

void displayNum(int num){
  int numArray[10] = {126,12,182,158,204,218,250,14,254,222};

  digitalWrite(latch,LOW);
  shiftOut(ds, clock, MSBFIRST, numArray[num]);
  digitalWrite(latch,HIGH);
}

void numOff(){
  byte data = 0;
  digitalWrite(latch,LOW);
  shiftOut(ds, clock, MSBFIRST, data);
  digitalWrite(latch,HIGH);
}

