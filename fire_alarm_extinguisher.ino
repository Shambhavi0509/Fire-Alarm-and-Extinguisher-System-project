// Fire Alarm & Extinguisher System - Full Version

// Pin Definitions
const int flameSensorPin = A0;   // Flame sensor (analog)
const int buzzerPin = 8;         // Buzzer
const int relayPin = 9;          // Relay to control water pump
const int ledPin = 7;            // Status LED
const int switchPin = 2;         // Slide switch

// Threshold for fire detection (adjust as needed)
const int flameThreshold = 100;

void setup() {
  // Setup pin modes
  pinMode(flameSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);  // Using internal pull-up resistor

  // Start serial monitor for debugging
  Serial.begin(9600);

  // Initial states
  digitalWrite(buzzerPin, LOW);
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, LOW);

  Serial.println("Fire Alarm & Extinguisher System Initialized");
}

void loop() {
  // Check if system is switched ON
  bool systemOn = digitalRead(switchPin) == LOW;  // Slide switch pressed

  if (systemOn) {
    digitalWrite(ledPin, HIGH);  // Turn ON status LED
    int flameValue = analogRead(flameSensorPin);  // Read flame sensor value

    // Print value for monitoring
    Serial.print("Flame Sensor Value: ");
    Serial.println(flameValue);

    // Check if flame is detected
    if (flameValue < flameThreshold) {
      Serial.println("🔥 Flame detected! Activating alarm and water pump.");
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(relayPin, HIGH);
    } else {
      Serial.println("✅ No flame detected. System in monitoring mode.");
      digitalWrite(buzzerPin, LOW);
      digitalWrite(relayPin, LOW);
    }

  } else {
    // System is turned off by slide switch
    Serial.println("🔌 System OFF (Slide switch)");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relayPin, LOW);
    digitalWrite(ledPin, LOW);
  }

  delay(300);  // Delay to avoid noise and reduce serial flooding
}
