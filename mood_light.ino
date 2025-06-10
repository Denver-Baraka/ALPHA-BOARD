#define LDR_PIN     A0
#define GREEN_LED   11
#define YELLOW_LED  12
#define RED_LED     13

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);

  Serial.print("Ambient light: ");
  Serial.println(lightLevel);

  if (lightLevel > 800) {
    // Very dark: green = cozy
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }
  else if (lightLevel > 400) {
    // Moderate: yellow = calm
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }
  else {
    // Bright: red = alert/awake
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }

  delay(200);
}
