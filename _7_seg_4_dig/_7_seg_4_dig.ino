// 7-segment 4-digit

int i;
const int a=2,b=3,c=4,d=5,e=6,f=7,g=8,dp=9,d0=10,d1=11,d2=12,d3=13;

void setup(){
  for (i = 2; i <= 13; i++){
    pinMode(i, OUTPUT);
  }
  digitalWrite(d0,HIGH);
  digitalWrite(d1,HIGH);
  digitalWrite(d2,HIGH);
  digitalWrite(d3,HIGH);
  i = 0;
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
  if (num == 0) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    return;
  }
  
  if (num == 1) {
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    return;
  }
  
  if (num == 2) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(g, HIGH);
    return;
  }
  
  if (num == 3) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(g, HIGH);
    return;
  }
  
  if (num == 4) {
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    return;
  }
  
  if (num == 5) {
    digitalWrite(a, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    return;
  }
  
  if (num == 6) {
    digitalWrite(a, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    return;
  }
  
  if (num == 7) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    return;
  }
  
  if (num == 8) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    return;
  }
  
  if (num == 9) {
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    return;
  }
}

void numOff(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
}

void displayDP(int i){
  if (i == 0) digitalWrite(dp,LOW);
  else digitalWrite(dp,HIGH);
}

void loop(){
  displayNum4(0);
}
