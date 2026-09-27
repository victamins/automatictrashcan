#include <Servo.h> 
 
Servo myservo;
#define echoPin 2
#define trigPin 3  // create servo object to control a servo 
float duration, distance;

void setup() 
{ 
  int pos;
  myservo.attach(9);
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  myservo.write(0);
} 
void loop() 
{ 

  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 400 || distance <= 2){
    Serial.print("Distance = ");
    Serial.println("Out of range");
  }
  else {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  if (distance <= 5) {
    myservo.write(90);
    delay(1500);
  } else if (distance >= 6) {
    myservo.write(0);
  }
  
} 
