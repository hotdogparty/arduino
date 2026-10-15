/* 
 Toggle 

 Toggles between two external LEDs (Red, Green) when a button is pressed. 

 Issues: 
 - No leds come on until the button is pressed
 - Holding the button down make bothe LEDs come on. 
 - Sometimes the LEDs don't toggle 

*/

#define LED_RED 8
#define LED_GREEN 9
#define BUTTON 2

int prevValue = 1;
int buttonState;
bool ledState = false;
unsigned long lastPressTime = 0;
unsigned long debounceTime = 50;  

void setup() {
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP);
    Serial.begin(115200);
    Serial.println("Serial output initialised.");
}

void toggleLed() {    
     ledState = !ledState;
    if (ledState) {
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_GREEN, HIGH);
    } else {
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_GREEN, LOW);     
    }
}

void loop() {

  // Read the button state
    int value = digitalRead(BUTTON);

  // Check if button was pressed (HIGH->LOW) *and* debounce time 
  // has elapsed since the last press

  // If button changed, reset debounce timer
  if (value != prevValue) {
    lastPressTime = millis();
  }

  // Only update state if debounce time has passed
  if((millis() - lastPressTime) > debounceTime) {
    buttonState = value;

    if(buttonState==LOW) {
      toggleLed();
    }
  }
  prevValue = value;
}
