/* 
 Blink 

 Based on example Arduino sketch, but blinks an external LED on PIN 8
*/

#define LED_RED 8
#define LED_GREEN 9
#define BUTTON 2

void setup() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    Serial.begin(115200);
    Serial.println("Serial output initialised.");
}

void loop() {
  int value = digitalRead(BUTTON);
  Serial.println(value);
  if (value == HIGH) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
  } else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
  }
  delay(100);
}
