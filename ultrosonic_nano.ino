const int trigPin = 6; // Trigger pin of HC-SR04
const int echoPin = 7; // Echo pin of HC-SR04
int buzzer = 4;
int isr_intr = 2;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(isr_intr, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Serial.begin(9600);
}

void loop() {
  long duration;
  float distance_cm;

  // Send trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in decimeters
  distance_cm = (duration * 0.034) / 2;

  // Print distance
  /*Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");
*/
  //delay(100); // Small delay between readings
 if(distance_cm < 30){
  digitalWrite(isr_intr,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(200);
   digitalWrite(buzzer,LOW);
  delay(200);
 
  }else{
    digitalWrite(isr_intr,LOW);
    }
}
