#define LED1_PIN 2
#define LED2_PIN 3
#define LED3_PIN 4
#define LED4_PIN 5

int led_pins[] = {LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN};

void setup() {
  Serial.begin(9600);
  for (int pin : led_pins) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);  // Ensure all LEDs are initially off
  }
}

void loop() {
  if (Serial.available() > 0) {
    int received = Serial.parseInt();  // Parse the incoming integer

    // Check if a valid integer was received
    if (received >= 0 && received <= 3) {
      // Turn off all LEDs
      for (int i = 0; i < 4; i++) {
        digitalWrite(led_pins[i], LOW);
      }

      // Turn on the corresponding LED based on parsed value
      digitalWrite(led_pins[received], HIGH);

      // Debug: Print received integer
      Serial.print("Received integer: ");
      Serial.println(received);
    } else {
      // Print an error message for invalid input
      Serial.print("Invalid integer received: ");
      Serial.println(received);
    }
  }
}
