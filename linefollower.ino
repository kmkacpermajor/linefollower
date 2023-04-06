#define slowSpeed 230
#define fastSpeed 255

#define LSO 15      // left sensor outer
#define RSO 16      // right sensor outer

#define LSI 17      // left sensor inner
#define RSI 18      // right sensor inner

#define LM1 4       // left motor
#define LM2 3       // left motor

#define RM1 7       // right motor
#define RM2 6       // right motor

#define LPWM 9
#define RPWM 10

void setup()

{
  pinMode(LSI, INPUT);
  pinMode(RSI, INPUT);
  pinMode(LSO, INPUT);
  pinMode(RSO, INPUT);

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  
  analogWrite(LPWM, 150);
  analogWrite(RPWM, 150);
}

void loop()

{

  if(!(digitalRead(LSI)) && !(digitalRead(RSI)) && !(digitalRead(LSO)) && !(digitalRead(RSO)))     // Move Forward
  {
    goStraight(slowSpeed);
  }

    if((digitalRead(LSI)) && (digitalRead(RSI)) && (digitalRead(LSO)) && (digitalRead(RSO)))     // stop
  {
    stop(slowSpeed);
  }

  if(!(digitalRead(LSI)) && (digitalRead(RSI)) && !(digitalRead(LSO)) && !(digitalRead(RSO)))     // Turn right inner
  {
    turnRight(slowSpeed);
  }

  if(!(digitalRead(LSO)) && (digitalRead(RSO)))     // Turn right outer
  {
    turnRight(fastSpeed);
  }

  if((digitalRead(LSI)) && !(digitalRead(RSI)) && !(digitalRead(LSO)) && !(digitalRead(RSO)))     // Turn left inner
  {
    turnLeft(slowSpeed);
  }

  if((digitalRead(LSO)) && !(digitalRead(RSO)))     // Turn left outer
  {
    turnLeft(fastSpeed);
  }

}

void goStraight(int speed){
  analogWrite(LPWM, speed);
  analogWrite(RPWM, speed);

  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}

void stop(int speed){
  analogWrite(LPWM, speed);
  analogWrite(RPWM, speed);

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, LOW);
}

void turnLeft(int speed){
  analogWrite(LPWM, speed);
  analogWrite(RPWM, speed);

  digitalWrite(LM1, HIGH);
  digitalWrite(LM2, LOW);
  digitalWrite(RM1, LOW);
  digitalWrite(RM2, HIGH);
}

void turnRight(int speed){
  analogWrite(LPWM, speed);
  analogWrite(RPWM, speed);

  digitalWrite(LM1, LOW);
  digitalWrite(LM2, HIGH);
  digitalWrite(RM1, HIGH);
  digitalWrite(RM2, LOW);
}