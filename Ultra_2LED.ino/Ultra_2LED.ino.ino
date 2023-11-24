// Define the pins for the ultrasonic sensor and LEDs
const int trigPin = 2; // Trigger pin of the ultrasonic sensor
const int echoPin = 3; // Echo pin of the ultrasonic sensor
const int greenLedPin = 4; // Pin for the green LED
const int redLedPin = 5;   // Pin for the red LED

// Variables for ultrasonic distance measurement
long duration;
int distance;

void setup() {
  // Initialize the sensor and LED pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  // Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Convert the duration to distance (in centimeters)
  distance = duration * 0.034 / 2;

  // Display the distance in the serial monitor (for debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Change LED colors based on distance
  if (distance > 30) {
    // Farther than 50 cm, turn on the green LED and turn off the red LED
    digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, LOW);
    
  } else if(distance <30 && distance >10) {
    // Closer than or equal to 50 cm, turn on the red LED and turn off the green LED
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  }
    else if (distance <10){
      digitalWrite(greenLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
    }

  // Delay before the next measurement
  delay(500);
}