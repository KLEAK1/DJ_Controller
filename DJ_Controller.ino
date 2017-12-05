// Encoder
/
#include <Encoder.h>
Encoder myEnc(33, 35);
int newPosition = 0;
int oldPosition = 0;
int usefulVal = 0;

Encoder myEnc2(37, 38);
int newPosition2 = 0;
int oldPosition2 = 0;
int usefulVal2 = 0;
int ccChannel9 = 9;

// Buttons
int buttonPin1 = 30; //play B
int buttonPin2 = 29; // cue B
int buttonPin3 = 2; // play A
int buttonPin4 = 1; // cue A

boolean lastButtonState1 = LOW;
boolean buttonState1 = LOW;
boolean lastButtonState2 = LOW;
boolean buttonState2 = LOW;
boolean lastButtonState3 = LOW;
boolean buttonState3 = LOW;
boolean lastButtonState4 = LOW;
boolean buttonState4 = LOW;

// Pots
int potPin = A12; //Master Volume
int newCCVal = 0;
int oldCCVal = 0;
int ccChannel1 = 1;

int potPin1 = A21; //Encoder Rate Set
int newCCValEnc = 0;
int oldCCValEnc = 0;
int encPosition = 5;
int ccChannel2 = 2;


int potPin2 = A20; //Volume Deck B
int newCCVal2 = 0;
int oldCCVal2 = 0;
int ccChannel3 = 3;

int potPin3 = A17; //EQ 1
int newCCVal3 = 0;
int oldCCVal3 = 0;
int ccChannel4 = 4;

int potPin4 = A2; //EQ 2
int newCCVal4 = 0;
int oldCCVal4 = 0;
int ccChannel5 = 5;

int potPin5 = A22; //Volume Deck A
int newCCVal5 = 0;
int oldCCVal5 = 0;
int ccChannel6 = 6;

int potPin6 = A3; //EQ 3
int newCCVal6 = 0;
int oldCCVal6 = 0;
int ccChannel7 = 7;

int potPin7 = A4; //EQ 4
int newCCVal7 = 0;
int oldCCVal7 = 0;
int ccChannel8 = 8;

int potPin8 = A5; //FX B
int newCCVal8 = 0;
int oldCCVal8 = 0;
int ccChannel10 = 10;

int potPin9 = A6; //FX A
int newCCVal9 = 0;
int oldCCVal9 = 0;
int ccChannel11 = 11;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

}

void loop() {
  checkButtons();
  checkPots();
  checkEncoder();
}

void checkButtons()  {
  lastButtonState1 = buttonState1;
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == HIGH && lastButtonState1 == LOW)  {
    usbMIDI.sendNoteOn(60, 127, 1);
    delay(500);
    digitalWrite (33, HIGH);
  }
  lastButtonState2 = buttonState2;
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == HIGH && lastButtonState2 == LOW)  {
    usbMIDI.sendNoteOn(62, 127, 1);
    delay(500);
    digitalWrite (33, HIGH);
  }
  lastButtonState3 = buttonState3;
  buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 == HIGH && lastButtonState3 == LOW)  {
    usbMIDI.sendNoteOn(64, 127, 1);
    delay(500);
    digitalWrite (33, HIGH);
  }
  lastButtonState4 = buttonState4;
  buttonState4 = digitalRead(buttonPin4);
  if (buttonState4 == HIGH && lastButtonState4 == LOW)  {
    usbMIDI.sendNoteOn(65, 127, 1);
    delay(500);
    digitalWrite (33, HIGH);
  }

}

void checkPots()  {
  // Master Volume
  oldCCVal = newCCVal;
  newCCVal = analogRead(potPin);
  newCCVal = map(newCCVal, 0, 1023, 0, 127);
  if (newCCVal != oldCCVal) {
    usbMIDI.sendControlChange(ccChannel1, newCCVal, 1);
    delay(10);
  }
  // Deck B Volume
  oldCCVal2 = newCCVal2;
  newCCVal2 = analogRead(potPin2);
  newCCVal2 = map(newCCVal2, 0, 1023, 0, 127);
  if (newCCVal2 != oldCCVal2) {
    usbMIDI.sendControlChange(ccChannel3, newCCVal2, 1);
  }

  // Eq1
  oldCCVal3 = newCCVal3;
  newCCVal3 = analogRead(potPin3);
  newCCVal3 = map(newCCVal3, 0, 1023, 0, 127);
  if (newCCVal3 != oldCCVal3) {
    usbMIDI.sendControlChange(ccChannel4, newCCVal3, 1);
  }

  // Eq2
  oldCCVal4 = newCCVal4;
  newCCVal4 = analogRead(potPin4);
  newCCVal4 = map(newCCVal4, 0, 1023, 0, 127);
  if (newCCVal4 != oldCCVal4) {
    usbMIDI.sendControlChange(ccChannel5, newCCVal4, 1);
  }

  // Deck A Volume
  oldCCVal5 = newCCVal5;
  newCCVal5 = analogRead(potPin5);
  newCCVal5 = map(newCCVal5, 0, 1023, 0, 127);
  if (newCCVal5 != oldCCVal5) {
    usbMIDI.sendControlChange(ccChannel6, newCCVal5, 1);
  }
  // Eq3
  oldCCVal6 = newCCVal6;
  newCCVal6 = analogRead(potPin6);
  newCCVal6 = map(newCCVal6, 0, 1023, 0, 127);
  if (newCCVal6 != oldCCVal6) {
    usbMIDI.sendControlChange(ccChannel7, newCCVal6, 1);
  }

  // Eq 4
  oldCCVal7 = newCCVal7;
  newCCVal7 = analogRead(potPin7);
  newCCVal7 = map(newCCVal7, 0, 1023, 0, 127);
  if (newCCVal7 != oldCCVal7) {
    usbMIDI.sendControlChange(ccChannel8, newCCVal7, 1);
  }

  // FX B
  oldCCVal8 = newCCVal8;
  newCCVal8 = analogRead(potPin8);
  newCCVal8 = map(newCCVal8, 0, 1023, 0, 127);
  if (newCCVal8 != oldCCVal8) {
    usbMIDI.sendControlChange(ccChannel10, newCCVal8, 1);
  }

  // FX A
  oldCCVal9 = newCCVal9;
  newCCVal9 = analogRead(potPin9);
  newCCVal9 = map(newCCVal9, 0, 1023, 0, 127);
  if (newCCVal9 != oldCCVal9) {
    usbMIDI.sendControlChange(ccChannel11, newCCVal9, 1);
  }

}

void checkEncoder() {
  oldCCValEnc = newCCValEnc;
  newCCValEnc = analogRead(potPin1);
  newCCValEnc = map(newCCValEnc, 0, 1023, 0, 127);
  encPosition = newCCValEnc;
  newPosition = myEnc.read();

  //every time you click the thing forward or backwards one click
  //it does four switching actions... which annoyingly sets the position
  //forward or backwards by 4, not 1.  So you check for when its position
  //moves up or down by 4, and that's one click forward or backwards.

  if (newPosition >= oldPosition + 4) {
    oldPosition = newPosition;
    usefulVal = oldPosition / 4;
    Serial.println(usefulVal);
    usbMIDI.sendControlChange(ccChannel2, encPosition, 1);
  } else if (newPosition <= oldPosition - 4) {
    oldPosition = newPosition;
    usefulVal = oldPosition / 4;
    Serial.println(usefulVal);
    usbMIDI.sendControlChange(ccChannel2, -(encPosition), 1);
  }
  newPosition2 = myEnc2.read();

  //every time you click the thing forward or backwards one click
  //it does four switching actions... which annoyingly sets the position
  //forward or backwards by 4, not 1.  So you check for when its position
  //moves up or down by 4, and that's one click forward or backwards.

  if (newPosition2 >= oldPosition2 + 4) {
    oldPosition2 = newPosition2;
    usefulVal2 = oldPosition2 / 4;
    Serial.println(usefulVal2);
    usbMIDI.sendControlChange(ccChannel9, encPosition, 1);
  } else if (newPosition2 <= oldPosition2 - 4) {
    oldPosition2 = newPosition2;
    usefulVal2 = oldPosition2 / 4;
    Serial.println(usefulVal2);
    usbMIDI.sendControlChange(ccChannel9, -(encPosition), 1);
  }
}
