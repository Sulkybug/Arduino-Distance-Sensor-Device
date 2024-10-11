Ultrasonic Distance Sensor with LED and Piezo Speaker
This project uses an ultrasonic distance sensor to measure the distance to an object and controls three LEDs (Green, Yellow, and Red) based on the detected distance. Additionally, a piezo speaker is used to emit different tones depending on which LED is active.

Features
Ultrasonic Distance Measurement: Measures the distance using an ultrasonic sensor.
LED Indicators:
Green LED turns on for distances between 183 cm and 336 cm.
Yellow LED turns on for distances between 89 cm and 183 cm.
Red LED turns on for distances below 89 cm, with a pulsing effect for distances under 50 cm.
Piezo Speaker:
Emits different beeps when LEDs are on, with frequencies adjusted based on the distance:
Green LED: 1000 Hz
Yellow LED: 1400 Hz
Red LED: 1700 Hz for distances between 50 cm and 89 cm, 2000 Hz for distances below 50 cm.
Hardware Requirements
1x Ultrasonic Distance Sensor
1x Piezo Speaker (connected to pin 4)
3x LEDs (Green, Yellow, and Red)
Jumper wires and breadboard
Pin Configuration
Red LED: Pin 7
Yellow LED: Pin 6
Green LED: Pin 5
Piezo Speaker: Pin 4
How it Works
The ultrasonic sensor measures the distance to the closest object.
Based on the distance, one of the three LEDs (Green, Yellow, Red) lights up.
The piezo speaker emits a specific tone based on the active LED.
The Red LED pulses when the distance is less than 50 cm, and the piezo beeps correspondingly.
Usage
Power the circuit and observe the distance readings on the serial monitor.
LEDs and piezo speaker will react according to the measured distance.
