#define TEMP_PIN    A3    
#define GREEN_LED   11
#define YELLOW_LED  12
#define RED_LED     13
#define BUZZER_PIN  9

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(TEMP_PIN);
  float voltage = raw * (5.0 / 1023.0);
  // Steinhart–Hart equation

  float tempC = (1.0 / (log(1023.0 / raw - 1.0) / 3950 + 1.0 / 298.15)) - 273.15;

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.println(" C");

  if (tempC < 28) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
  else if (tempC < 32) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
  else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  }

  delay(500);
}
