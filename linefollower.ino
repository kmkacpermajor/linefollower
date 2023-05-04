#define straightSpeed 160
#define turnSpeed 255

#define LSOP 3      // left sensor outer
#define RSOP 14      // right sensor outer

#define LSIP 4      // left sensor inner
#define RSIP 13      // right sensor inner

#define LM1 11       // left motor
#define LM2 7       // left motor

#define RM1 6       // right motor
#define RM2 8       // right motor

#define LPWM 9
#define RPWM 10

void setup()

{
  pinMode(LSIP, INPUT);
  pinMode(RSIP, INPUT);
  pinMode(LSOP, INPUT);
  pinMode(RSOP, INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
}

void loop()
{
  // DDRB |= 0b00000011; 
  // TCCR0A |= 0b10000011;
  // TCCR1A |= 0b10000011;
  
  int LSO = digitalRead(LSOP);
  int LSI = digitalRead(LSIP);
  int RSI = digitalRead(RSIP);
  int RSO = digitalRead(RSOP);

  if ((LSO && LSI && RSI && RSO)
  || (!(LSO) && !(LSI) && !(RSI) && !(RSO)))
  {
    goStraight();
  }

  if (LSO && LSI && !RSI && !RSO)
  {
    turnLeft();
  }

  if (!LSO && !LSI && RSI && RSO)
  {
    turnRight();
  }

  if (LSO && !LSI && !RSI && !RSO){
    turnLeft();
  }

  if (!LSO && LSI && !RSI && !RSO)
  {
    turnLeft();
  }

  if (!LSO && !LSI && !RSI && RSO)
  {
    turnRight();
  }

  if(!LSO && !LSI && RSI && !RSO)
  {
    turnRight();
  }

}

void goStraight(){
  analogWrite(LPWM, straightSpeed);
  analogWrite(RPWM, straightSpeed);

  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void turnLeft(){
  analogWrite(LPWM, turnSpeed);
  analogWrite(RPWM, turnSpeed);

  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void turnRight(){
  analogWrite(LPWM, turnSpeed);
  analogWrite(RPWM, turnSpeed);

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}
