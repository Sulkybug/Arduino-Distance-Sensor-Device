const int ledPinRed = 7;  // Pin 7 for the LED
const int ledPinYellow = 6;  // Pin 6 for the LED
const int ledPinGreen = 5;  // Pin 5 for the LED
long time;
long cm;
void setup()
{
  Serial.begin(9600);
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); 
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}


void loop(){
time = readUltrasonicDistance(10,10);
  cm = 0.01723*time;
 Serial.println("Distance: " + String(cm) + " cm");
  
      // Green LED condition
  if (cm < 336 && cm >= 183) {
    digitalWrite(ledPinGreen, HIGH);  // Turn Green LED ON
  } else {
    digitalWrite(ledPinGreen, LOW);   // Turn Green LED OFF
  }

  // Yellow LED condition
  if (cm < 183 && cm >= 80) {
    digitalWrite(ledPinYellow, HIGH); // Turn Yellow LED ON
  } else {
    digitalWrite(ledPinYellow, LOW);   // Turn Yellow LED OFF
  }

  // Red LED control
  if (cm <= 50) {
    // Pulse the Red LED
    digitalWrite(ledPinRed, HIGH);  // Turn Red LED ON
    delay(300);                      // Keep it ON for 300 milliseconds
    digitalWrite(ledPinRed, LOW);   // Turn Red LED OFF
    delay(300);                      // Keep it OFF for 300 milliseconds
  } else if (cm < 80 && cm > 50) {
    digitalWrite(ledPinRed, HIGH);  // Turn Red LED ON if distance is between 51 and 80 cm
  } else {
    digitalWrite(ledPinRed, LOW);   // Turn Red LED OFF if distance is 80 cm or more
  }


  delay(100);  // Small delay to avoid flooding the serial monitor
}
