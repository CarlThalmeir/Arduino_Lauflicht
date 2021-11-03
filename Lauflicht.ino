// Author: Carl Thalmeir
// Date: 03.11.2021
//
// What to do: connect LEDs, Potentiometers (Poti) and two Buttons to Arduino Uno, then fill in the Pin numbers below.
// Then press some buttons.

int LEDs [] {11, 10, 9, 6, 5, 3};
const int length = sizeof(LEDs) / sizeof(int);
int PotiPin = 3;
int BUTTON1 = 1;
int BUTTON2 = 2;

//----------SETUP---------------------------------------------------------------------------------------------------------------

void setup() {

  Serial.begin(9600);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);

  for (int i = 0; i <= length - 1; ++i) {
    pinMode (LEDs [i], OUTPUT);
  }
}

//----------LOOP-----------------------------------------------------------------------------------------------------------------

void loop() {

  Mode1 ();         // lights turn on an off after on another
  Mode2 ();         // lights flash
  Mode3 ();         // every second light flashes

  if (digitalRead (BUTTON2) == 1 && digitalRead (BUTTON1) == 1) {
    Mode4Fade1 ();
    Mode4Fade2 ();
    Mode4Fade3 ();
    Mode4Fade4 ();
  }
}

//----------MODE1---------// lights turn on an off after on another //------------------------------------------------------------

void Mode1 () {
  int speed = (analogRead(PotiPin));    // The Poti controls the speed of the lights flashing/ moving (exept mode4)
  if (digitalRead (BUTTON1) == 0 && digitalRead (BUTTON2) == 0) {
    for (int i = 0 ; i <= length - 1 ; ++i) {
      analogWrite(LEDs [i], 255);
      delay(speed);
      analogWrite(LEDs [i], 0);
    }
  }
}

//----------MODE2---------// lights flash //---------------------------------------------------------------------------------------

void Mode2 () {
  int speed = (analogRead(PotiPin));
  if (digitalRead (BUTTON1) == 0 && digitalRead (BUTTON2) == 1) {
    for (int i = 0 ; i <= length - 1 ; ++i) {
      analogWrite(LEDs [i], 255);
    }
    delay(speed);
    for (int i = 0 ; i <= length - 1 ; ++i) {
      analogWrite(LEDs [i], 0);
    }
    delay(speed);
  }
}

//----------MODE3----------// every second light flashes //-------------------------------------------------------------------------

void Mode3 () {
  int speed = (analogRead(PotiPin));
  if (digitalRead (BUTTON2) == 0 && digitalRead (BUTTON1) == 1) {
    for (int i = 0 ; i <= length - 1 ; i = i + 2) {
      analogWrite(LEDs [i], 255);
    }
    delay(speed);
    for (int i = 0 ; i <= length - 1 ; i = i + 2) {
      analogWrite(LEDs [i], 0);
    }
    delay(speed);
  }
}

//----------MODE4-(fade)-----// Kitt style light fading //---------------------------------------------------------------------------

int speed2 = 130;       // delay in Microsekunden for mode 4 (fade)

void Mode4Fade1 () {
  for (int LEDnr = 0; LEDnr <= length - 1 ; ++LEDnr) {
    for (int brightness = 0 ; brightness <= 255 ; ++brightness) {
      analogWrite(LEDs [LEDnr], brightness);
      delayMicroseconds(speed2);
    }
  }
}

void Mode4Fade2 () {
  for (int LEDnr = 0; LEDnr <= length - 1 ; ++LEDnr) {
    for (int brightness = 255 ; brightness >= 0 ; brightness = brightness - 1) {
      analogWrite(LEDs [LEDnr], brightness);
      delayMicroseconds(speed2);
    }
  }
}

void Mode4Fade3 () {
  for (int LEDnr = length - 1; LEDnr >= 0 ; --LEDnr) {
    for (int brightness = 0 ; brightness <= 255 ; ++brightness) {
      analogWrite(LEDs [LEDnr], brightness);
      delayMicroseconds(speed2);
    }
  }
}

void Mode4Fade4 () {
  for (int LEDnr = length - 1 ; LEDnr >= 0 ; --LEDnr) {
    for (int brightness = 255 ; brightness >= 0 ; brightness = brightness - 1) {
      analogWrite(LEDs [LEDnr], brightness);
      delayMicroseconds(speed2);
    }
  }
}
//------END---------------------------------------------------------------------------------------------------------------------
