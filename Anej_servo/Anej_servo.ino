/*
  Krmiljenje dveh RC servo motorjev.
  Uporabljen je Joystick
*/

#include <Servo.h>

Servo myservo;     // ustvari servo objekt za nadzor serva
Servo myservo1;    // ustvari servo objekt za nadzor serva

int potpin = 0;    // analogni pin na katerga je priključen potenciometer
int val;           // spremenljivka za branje vrednosti iz analognega pina
int potpin1 = 1;   // analogni pin na katerga je priključen potenciometer
int val1;          // spremenljivka za branje vrednosti iz analognega pina

void setup() {
  myservo.attach(10);  // priključi servo na pin 10
  myservo1.attach(9);  // priključi servo na pin 9
}

void loop() {
  val = analogRead(potpin);            // prebere vrednost potenciometra (vrednost med 0 in 1023)
  val = map(val, 0, 1023, 0, 180);     // pretvori v merilo za servo (vrednost med 0 in 180)
  myservo.write(val);                  // nastavi položaj servo po pretvorjeni vrednosti
  delay(15);                           // počaka da servo pride do tja
  val1 = analogRead(potpin1);          // prebere vrednost potenciometra (vrednost med 0 in 1023)
  val1 = map(val1, 0, 1023, 0, 180);   // pretvori v merilo za servo (vrednost med 0 in 180)
  myservo1.write(val1);                // nastavi položaj servo po pretvorjeni vrednosti
  delay(15);                           // počaka da servo pride do tja
}

