/* 
 Blink 

 Based on example Arduino sketch, but blinks an external LED on PIN 8
*/

#define LED 8

void setup() {
    pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
