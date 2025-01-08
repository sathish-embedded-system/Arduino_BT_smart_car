// Define LED pins
const int LED1 = 8;  // LED1 pin
const int LED2 = 9;  // LED2 pin
const int interruptPin = 2;  // Interrupt pin for button

volatile bool led1State = false;  // Flag to track LED1 state

void setup() {
  // Set LED pins as output
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  // Set the interrupt pin as input with internal pull-up
  pinMode(interruptPin, INPUT_PULLUP);

  // Attach an interrupt to the interrupt pin
  attachInterrupt(digitalPinToInterrupt(interruptPin), handleInterrupt, FALLING);
}

void loop() {
  if (led1State) {
    // Turn on LED1
    digitalWrite(LED1, HIGH);

    // Ensure LED2 remains off
    digitalWrite(LED2, LOW);
  } else {
    // Blink LED2
    digitalWrite(LED2, HIGH);
    delay(500);
    digitalWrite(LED2, LOW);
    delay(500);
  }
}

// Interrupt Service Routine (ISR)
void handleInterrupt() {
  // Set the state of LED1 to true (turn it on)
  led1State = true;

  // Disable further interrupts to avoid repeated triggering
  detachInterrupt(digitalPinToInterrupt(interruptPin));
}

