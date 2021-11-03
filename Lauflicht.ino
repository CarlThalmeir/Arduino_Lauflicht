int LEDs [] {11, 10, 9, 6, 5, 3};
const int length = sizeof(LEDs) / sizeof(int);
int PotiPin = 3;
int Taster1 = 1;
int Taster2 = 2;

void setup() {

Serial.begin(9600);
pinMode(Taster1, INPUT);
pinMode(Taster2, INPUT);

for (int LEDArray = 0; LEDArray <= length - 1; ++LEDArray) {
  pinMode (LEDs [LEDArray], OUTPUT);
}
}

void loop() {

int speed = (analogRead(PotiPin));

if (digitalRead (Taster1) == 0 && digitalRead (Taster2) == 0) {                                                                    // Lauflicht
 for (int LEDArray2 = 0 ; LEDArray2 <= length - 1 ; ++LEDArray2) {                                                                 // nichts gedrückt
  analogWrite(LEDs [LEDArray2], 255);
  delay(speed);
  analogWrite(LEDs [LEDArray2], 0); 
  } 
}
if (digitalRead (Taster1) == 0 && digitalRead (Taster2) ==1) { 
  for (int Taster1CounterAn = 0 ; Taster1CounterAn <= length - 1 ; ++Taster1CounterAn) {                                          // Alle Lichter blinken
    analogWrite(LEDs [Taster1CounterAn], 255);                                                                                    // Taster 1 gedrückt
  }
  delay(speed);
  for (int Taster1CounterAus = 0 ; Taster1CounterAus <= length - 1 ; ++Taster1CounterAus) {
    analogWrite(LEDs [Taster1CounterAus], 0);
  }
  delay(speed); 
} 
if (digitalRead (Taster2) == 0 && digitalRead(Taster1)==1) {
   for (int Taster2CounterAn = 0 ; Taster2CounterAn <= length - 1 ; Taster2CounterAn = Taster2CounterAn + 2) {                   // Jedes zweite Licht blinkt
    analogWrite(LEDs [Taster2CounterAn], 255);                                                                                   // Taster 2 gedrückt
  }
  delay(speed);
  for (int Taster2CounterAus = 0 ; Taster2CounterAus <= length - 1 ; Taster2CounterAus = Taster2CounterAus + 2) {
    analogWrite(LEDs [Taster2CounterAus], 0);
  }
  delay(speed); 
}
if (digitalRead (Taster2) == 1 && digitalRead ( Taster1) == 1) {
  Modus41 ();                                                                                                                    // Kitt Light Bar
  Modus42 ();                                                                                                                    // nichts gedrückt
  Modus43 ();
  Modus44 ();
}
}

int speed2 = 130;

void Modus41 () {
    for (int KitLicht1LEDArray = 0; KitLicht1LEDArray <= length -1 ; ++KitLicht1LEDArray) {
      for (int KitLicht1 = 0 ; KitLicht1 <= 255 ; ++KitLicht1) {
        analogWrite(LEDs [KitLicht1LEDArray], KitLicht1);
        delayMicroseconds(speed2);
    }
  }
}


void Modus42 () {
  for (int KitLicht2LEDArray = 0; KitLicht2LEDArray <= length -1 ; ++KitLicht2LEDArray) {
      for (int KitLicht2 = 255 ; KitLicht2 >= 0 ; KitLicht2 = KitLicht2 - 1) {
        analogWrite(LEDs [KitLicht2LEDArray], KitLicht2);
        delayMicroseconds(speed2);
    }
  }
}


void Modus43 () {
    for (int KitLicht3LEDArray = length -1; KitLicht3LEDArray >= 0 ; --KitLicht3LEDArray) {
      for (int KitLicht3 = 0 ; KitLicht3 <= 255 ; ++KitLicht3) {
        analogWrite(LEDs [KitLicht3LEDArray], KitLicht3);
        delayMicroseconds(speed2);
    }
  }
}


void Modus44 () {
  for (int KitLicht4LEDArray = length -1 ; KitLicht4LEDArray >= 0 ; --KitLicht4LEDArray) {
      for (int KitLicht4 = 255 ; KitLicht4 >= 0 ; KitLicht4 = KitLicht4 - 1) {
        analogWrite(LEDs [KitLicht4LEDArray], KitLicht4);
        delayMicroseconds(speed2);
    }
  }
}
