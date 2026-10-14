/* 
 Blink 

 Based on example Arduino sketch, but blinks an external LED on PIN 8
*/

#define LED_RED 8
#define LED_GREEN 9

void setup() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
}

void loop() {


  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, LOW);
  delay(1000);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, HIGH);
  delay(1000);
}
