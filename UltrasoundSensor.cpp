const int ledPinRed = 7;  // Pin 7 for the LED
const int ledPinYellow = 6;  // Pin 6 for the LED
const int ledPinGreen = 5;  // Pin 5 for the LED
const int piezoPin = 4;     // Pin 4 for the piezo speaker
long time;
float cm;

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
 Serial.print("Distance: ");
  Serial.print(cm, 1);  // Print with 1 decimal place
  Serial.println(" cm");
  
      // Green LED condition
  if (cm < 336 && cm >= 183) {
    digitalWrite(ledPinGreen, HIGH);  // Turn Green LED ON
    tone(piezoPin, 1000); // Beep with a 1000 Hz tone
    delay(300);
     noTone(piezoPin);               // Stop beep
    delay(300);  
  } else {
    digitalWrite(ledPinGreen, LOW);   // Turn Green LED OFF
    noTone(piezoPin);               // Stop beep
  }

  // Yellow LED condition
  if (cm < 183 && cm >= 89) {
    digitalWrite(ledPinYellow, HIGH); // Turn Yellow LED ON
    tone(piezoPin, 1400); // Beep with a 1400 Hz tone
    delay(200);
     noTone(piezoPin);               // Stop beep
    delay(200);  
  } else {
    digitalWrite(ledPinYellow, LOW);   // Turn Yellow LED OFF
    noTone(piezoPin);               // Stop beep
  }

  // Red LED control
  if (cm <= 50) {
    // Pulse the Red LED
    digitalWrite(ledPinRed, HIGH);  // Turn Red LED ON
    tone(piezoPin, 2000); // Beep with a 2000 Hz tone
    delay(100);                      // Keep it ON for 300 milliseconds
    digitalWrite(ledPinRed, LOW);   // Turn Red LED OFF
    tone(piezoPin, 2000); // Beep with a 2000 Hz tone
    delay(100);                      // Keep it OFF for 300 milliseconds
  } else if (cm < 89 && cm > 50) {
    digitalWrite(ledPinRed, HIGH);  // Turn Red LED ON if distance is between 51 and 88 cm
    tone(piezoPin, 1700); // Beep with a 1700 Hz tone
     delay(160);
     noTone(piezoPin);               // Stop beep
    delay(160);  
  } else {
    digitalWrite(ledPinRed, LOW);   // Turn Red LED OFF if distance is 80 cm or more
    noTone(piezoPin);               // Stop beep
  }


  delay(100);  // Small delay to avoid flooding the serial monitor
}
