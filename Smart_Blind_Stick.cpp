/*
 * make a smart stick that helps the Blind
 * (Updated with blinking LED and logic fixes)
 */
#define trigPin 9
#define echoPin 8

// #define Buzzer1 5 //active  <-- REMOVED
#define Buzzer2 7 // passive
#define Led1 6    // Vibration Motor

void setup() {
  // Serial.begin() only needs to be called ONCE
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // pinMode(Buzzer1, OUTPUT); <-- REMOVED
  pinMode(Buzzer2, OUTPUT);
  pinMode(Led1, OUTPUT);
}

void loop() {
  // 1. Get the sensor reading
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Use delayMicroseconds for more precise timing
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // 2. Check the distance using an "if... else if... else" structure.
  // This provides 3 distinct levels of sound alerts using ONLY Buzzer2.

  if (distance < 10) {
    // --- Closest: Level 3 Sound (Fast Pulse + High Tone) ---
    // A fast, high-pitched pulse from the passive buzzer.

    // Pulse LED (vibration) and Passive Buzzer (high tone)
    digitalWrite(Led1, HIGH);
    tone(Buzzer2, 1200); // High pitch
    delay(100);

    digitalWrite(Led1, LOW);
    noTone(Buzzer2); // Stop the tone to create a pulse
    delay(100);

  } else if (distance < 20) {
    // --- Medium: Level 2 Sound (Medium Pulse) ---
    // Pulse LED (vibration) and Passive Buzzer (medium tone)
    digitalWrite(Led1, HIGH);
    tone(Buzzer2, 800); // Medium pitch
    delay(250);

    digitalWrite(Led1, LOW);
    noTone(Buzzer2); // Stop the tone
    delay(250);

  } else if (distance < 40) {
    // --- Far: Level 1 Sound (Slow Beep) ---
    // This logic was already correct for Buzzer2

    // Pulse LED (vibration) and Passive Buzzer (with a low tone)
    digitalWrite(Led1, HIGH);
    tone(Buzzer2, 440); // A low-pitch "A" note
    delay(500);

    digitalWrite(Led1, LOW);
    noTone(Buzzer2); // Turn off the tone
    delay(500);

  } else {
    // --- Nothing is close (distance >= 40) ---
    // This "else" block runs when no objects are detected.
    // Turn EVERYTHING off.
    digitalWrite(Led1, LOW);
    // digitalWrite(Buzzer1, LOW); <-- REMOVED
    noTone(Buzzer2); // Make sure passive buzzer is off
  }

  // We don't need a final delay here because the
  // delays inside the "if" blocks control the loop speed.
}