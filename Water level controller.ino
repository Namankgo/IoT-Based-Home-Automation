/* Change these values based on your calibration values */
int lowerThreshold = 250;
int upperThreshold = 520;

// Sensor pins
#define sensorPower 2
#define sensorPin 4

// Value for storing water level
int val = 0;

// Declare pins to which LEDs are connected
int buzzer = 5;

void setup() {
	Serial.begin(9600);
	pinMode(sensorPower, OUTPUT);
	digitalWrite(sensorPower, LOW);
	
	// Set LED pins as an OUTPUT
	pinMode(buzzer, OUTPUT);

	// Initially turn off all LEDs
	digitalWrite(buzzer, LOW);
}

void loop() {
	int level = readSensor();


	if (level <= lowerThreshold) {
		Serial.println("Water Level: Low");
		digitalWrite(buzzer, LOW);
	}
	else if (level > lowerThreshold && level <= upperThreshold) {
		Serial.println("Water Level: Medium");
		digitalWrite(buzzer, LOW);
	}
	else if (level > upperThreshold) {
		Serial.println("Water Level: High");
		digitalWrite(buzzer, HIGH);
	}
	delay(1000);
}

//This is a function used to get the reading
int readSensor() {
	digitalWrite(sensorPower, HIGH);
	delay(10);
	val = analogRead(sensorPin);
	digitalWrite(sensorPower, LOW);
	return val;
}
