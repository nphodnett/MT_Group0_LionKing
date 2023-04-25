#include <Servo.h>

#include <Servo.h>

//servos
Servo wheel;
Servo hook;
Servo sign;
Servo sign1;

const int wheelServo = 1;
const int hookServo = 2;
const int signServo = 3;
const int sign1Servo = 4;

//buttons
const int onButton = 5;
const int scarButton = 6;
const int scar2Button = 7;
const int simbaButton = 8;

//LEDS
const int redLED = 9;
const int redLED1 = 10;
const int greenLED = 11;

//servo rotations
const int wheelRotation1 = 86;
const int wheelRotation2 = 100;
int wheelRotate = wheelRotation1;

const int signRotation1 = 88;
const int signRotation2 = 0;
int signRotate = signRotation1;

const int sign1Rotation1;
const int sign1Rotation2;
int sign1Rotate = sign1Rotation1;

const int hookRotation1;
const int hookRotation2;
int hookRotate = hookRotation1;

//LED states
int redLEDState = LOW;
int redLED1State = LOW;
int greenLEDState = LOW;

//button states
int onStateLast;
int scarStateLast;
int scar2StateLast;
int simbaStateLast;



void setup() {


  //pinmodes
  pinMode(redLED, OUTPUT);
  pinMode(redLED1, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(scarButton, INPUT);
  pinMode(scar2Button, INPUT);
  pinMode(simbaButton, INPUT);
  pinMode(onButton, INPUT);

  //servo attach
  wheel.attach(wheelServo);
  hook.attach(hookServo);
  sign.attach(signServo);
  sign1.attach(sign1Servo);

  onStateLast = digitalRead(onButton);
  scarStateLast = digitalRead(scarButton);
  scar2StateLast = digitalRead(scar2Button);
  simbaStateLast = digitalRead(simbaButton);
}

void loop() {


  int onStateCurrent = digitalRead(onButton);

  if (onStateCurrent != onStateLast) {
    onStateLast = onStateCurrent;
    if (onStateCurrent == LOW) {
      if (redLEDState == HIGH) {
        redLEDState = LOW;
        wheelRotate = wheelRotation1;
      } else {
        redLEDState = HIGH;
        wheelRotate = wheelRotation2;
      }
    }
    digitalWrite(redLED, redLEDState);
    wheel.write(wheelRotate);
  }

  int scarStateCurrent = digitalRead(scarButton);

  if (scarStateCurrent != scarStateLast) {
    scarStateLast = scarStateCurrent;
    if (scarStateCurrent == LOW) {
      if (signRotate == signRotation2) {
        signRotate = signRotation1;
      } else {
        signRotate = signRotation2;
        redLEDState = LOW;
        greenLEDState = HIGH;
        hookRotate = hookRotation2;
      }
     // sign.write(signRotate);
      digitalWrite(redLED, redLEDState);
      delay(2000);
      hook.write(hookRotate);
      delay(2000);
      wheel.write(wheelRotation1);
      digitalWrite(greenLED, greenLEDState);
    }
  }
  
  int simbaStateCurrent = digitalRead(simbaButton);

  if (simbaStateCurrent != simbaStateLast) {
    simbaStateLast  = simbaStateCurrent;
    if (simbaStateCurrent == LOW) {

    } else {
      redLED1State = HIGH;
      greenLEDState = LOW;
    }
    digitalWrite(redLED1, redLED1State);
    digitalWrite(greenLED, greenLEDState);
  }

  int scar2StateCurrent = digitalRead(scar2Button);

  if(scarStateCurrent != scarStateLast) {
    scarStateLast = scarStateCurrent;
    if(scarStateCurrent == LOW){

    }else {
      sign1Rotate = sign1Rotation2;
      redLED1State = LOW;
    }
    sign1.write(sign1Rotate);
    digitalWrite(redLED1, redLED1State);
  }

}
