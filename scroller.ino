#define RED_LED     13
#define YELLOW_LED  12
#define GREEN_LED   11

#define BUTTON_UP   A4
#define BUTTON_DOWN A5

int currentLED = 0;
const int leds[] = {GREEN_LED, YELLOW_LED, RED_LED}; 
const int numLEDs = 3;

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(leds[i], OUTPUT);
  }

  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);

  updateLEDs();
}

void loop() {
  static bool upPressed = false;
  static bool downPressed = false;

  // Button 1 (scroll up)
  if (digitalRead(BUTTON_UP) == LOW) {
    if (!upPressed) {
      currentLED = (currentLED + 1) % numLEDs;
      updateLEDs();
      upPressed = true;
    }
  } else {
    upPressed = false;
  }

  // Button 2 (scroll down)
  if (digitalRead(BUTTON_DOWN) == LOW) {
    if (!downPressed) {
      currentLED = (currentLED - 1 + numLEDs) % numLEDs;
      updateLEDs();
      downPressed = true;
    }
  } else {
    downPressed = false;
  }

  delay(50); //debouncing
}

void updateLEDs() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(leds[i], i == currentLED ? HIGH : LOW);
  }
}
