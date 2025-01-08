const int motorPin = 8;        // Motor control pin
const int interruptPin = 2;    // Interrupt pin connected to the switch
const int ledPin = 13;         // LED pin for status indication
volatile bool motorState = false; // Motor state (ON or OFF)

void setup() {
  pinMode(motorPin, OUTPUT);         // Set motor pin as output
  pinMode(interruptPin, INPUT_PULLUP); // Enable pull-up resistor for the switch pin
  pinMode(ledPin, OUTPUT);           // Set LED pin as output

  attachInterrupt(digitalPinToInterrupt(interruptPin), toggleMotor, CHANGE); // Trigger interrupt on state change
  
}

void loop() {
  // Main task: Toggle LED to indicate system is running
  digitalWrite(ledPin, HIGH);
  delay(500); // LED ON for 500ms
  digitalWrite(ledPin, LOW);
  delay(500); // LED OFF for 500ms

}

// Interrupt Service Routine (ISR)
void toggleMotor() {
  // Read the state of the interrupt pin
  if (digitalRead(interruptPin) == HIGH) { // sensor signal
    motorState = true;  
    // Turn motor ON
    digitalWrite(motorPin, HIGH);
    delay(1000);
    
  } else { // Switch released
    motorState = false;              // Turn motor OFF
    digitalWrite(motorPin, LOW);
   
  }
}
