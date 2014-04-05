// 7-segment LED

int i;
const int a=2,b=3,c=4,d=5,e=6,f=7,g=8,dp=9;

void setup(){
  for (i = 2; i <= 9; i++){
    pinMode(i, OUTPUT);
  }
  i = 0;
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
  displayNum(i);
  delay(1000);
  numOff();
  i = (i+1)%10;
  displayDP(i%2);
}
