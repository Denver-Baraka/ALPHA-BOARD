// Note frequencies
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494

#define BUZZER_PIN 9
#define POT_PITCH  A2
#define POT_SPEED  A1

#define GREEN_LED  11
#define YELLOW_LED 12
#define RED_LED    13

//simple 7-note melody
int melody[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_A4, NOTE_B4
};

// Durations
int noteDurations[] = {
  4, 4, 4, 4,
  4, 4, 4
};

int ledPins[] = {GREEN_LED, YELLOW_LED, RED_LED};

void setup() {
  for (int i = 0; i < 3; i++) pinMode(ledPins[i], OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int pitchControl = analogRead(POT_PITCH); // A2
  float pitchFactor = map(pitchControl, 0, 1023, 50, 200); // adjust range
  pitchFactor /= 100.0; // 0.5 to 2.0

  int speedControl = analogRead(POT_SPEED); // A1
  int ledDelay = map(speedControl, 0, 1023, 100, 1000); // LED change speed

  for (int i = 0; i < 7; i++) {
    int noteDuration = 1000 / noteDurations[i];
    int freq = melody[i] * pitchFactor;

    tone(BUZZER_PIN, freq, noteDuration);
    delay(noteDuration * 1.2);

    // Light up LEDs in pattern with user-set delay
    for (int j = 0; j < 3; j++) {
      digitalWrite(ledPins[j], HIGH);
      delay(ledDelay);
      digitalWrite(ledPins[j], LOW);
    }
  }

  noTone(BUZZER_PIN);
  delay(500); // Pause between repeats
}
