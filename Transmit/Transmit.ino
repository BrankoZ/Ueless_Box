/*Example Program - Transmit
  https://www.pjrc.com/teensy/td_libs_VirtualWire.html
  na povezavi je tudi VirtualWire knjižnica, ki sem jo uporabil
  opis uporabe knjižnice: http://www.airspayce.com/mikem/arduino/VirtualWire.pdf
*/
#include <VirtualWire.h>

const int led_pin = 13;       // LED na Arduinu za kontrolo
const int transmit_pin = 12;  // Data pin oddajnika
int S1 = 0;          // analogni pin na katerga je priključen potenciometer za prvi servo
int Servo0;          // spremenljivka za branje vrednosti iz analognega pina
int S2 = 1;          // analogni pin na katerga je priključen potenciometer za drugi servo
int Servo1;          // spremenljivka za branje vrednosti iz analognega pina
int M1 = 2;          // analogni pin na katerga je priključen potenciometer za prvi motor
int Motor1;          // spremenljivka za branje vrednosti iz analognega pina
int M2 = 3;          // analogni pin na katerga je priključen potenciometer za drugi motor
int Motor2;          // spremenljivka za branje vrednosti iz analognega pina
int M3 = 4;          // analogni pin na katerga je priključen potenciometer za tretji motor
int Motor3;          // spremenljivka za branje vrednosti iz analognega pina
int M4 = 5;          // analogni pin na katerga je priključen potenciometer za četrti motor
int Motor4;          // spremenljivka za branje vrednosti iz analognega pina

void setup() 
{
  // Inicializacija IO in ISR
  vw_set_tx_pin(transmit_pin);
  vw_setup(2000);        // Bitov na sekundo hitrost prenosa
//  Serial.begin(9600);  // samo za kontrolo v terminalu (odkomentiraj če rabiš)
}
void loop() 
{
  // pretvarjanje podatkov
  Servo0 = analogRead(S1);                 // prebere vrednost potenciometra (vrednost med 0 in 1023)
  Servo0 = map(Servo0, 0, 1023, 0, 180);   // pretvori v merilo za servo (vrednost med 0 in 180)
  Servo1 = analogRead(S2);                 // prebere vrednost potenciometra (vrednost med 0 in 1023)
  Servo1 = map(Servo1, 0, 1023, 0, 180);   // pretvori v merilo za servo (vrednost med 0 in 180)
  Motor1 = analogRead(M1);                 // prebere vrednost potenciometra (vrednost med 0 in 1023)
  Motor1 = map(Motor1, 0, 1023, 0, 200);   // pretvori v merilo za servo (vrednost med 0 in 200)
  Motor2 = analogRead(M2);                 // prebere vrednost potenciometra (vrednost med 0 in 1023)
  Motor2 = map(Motor2, 0, 1023, 0, 200);   // pretvori v merilo za servo (vrednost med 0 in 200)
  Motor3 = analogRead(M3);                 // prebere vrednost potenciometra (vrednost med 0 in 1023)
  Motor3 = map(Motor3, 0, 1023, 0, 200);   // pretvori v merilo za servo (vrednost med 0 in 200)
  Motor4 = analogRead(M4);                 // prebere vrednost potenciometra (vrednost med 0 in 1023)
  Motor4 = map(Motor4, 0, 1023, 0, 200);   // pretvori v merilo za servo (vrednost med 0 in 200)
  
  // pošiljanje podatkov
  char msg[6] = {Servo0, Servo1, Motor1, Motor2, Motor3, Motor4};
  digitalWrite(led_pin, HIGH);             // prižge LED
  vw_send((uint8_t *)msg, 6);
  vw_wait_tx();                            // počaka, da so vsi podatki poslani
  digitalWrite(led_pin, LOW);              // ugasne LED, vsi podatki sš poslani
  delay(1);
}

