// #include <Arduino.h>

// const byte ledPin = 13;

// const byte interruptPin = 2;

// volatile byte state = LOW;

// void glow()
// {
//   Serial.println("Interrupt is triggered");
//   state = !state;
// }

// void setup()
// {

//   Serial.begin(9600);

//   pinMode(ledPin, OUTPUT);

//   pinMode(interruptPin, INPUT_PULLUP);

//   attachInterrupt(digitalPinToInterrupt(interruptPin), glow, CHANGE);
// }

// void loop()
// {
//   digitalWrite(ledPin, state);
// }
