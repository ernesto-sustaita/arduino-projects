#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo servoMotor;
int lectura = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup(){
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(9);
  Serial.begin(9600);
}

void loop()
{
  lectura = 0.01723 * readUltrasonicDistance(2, 3);
  
  if (lectura <= 20) {
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    // Desplazamos a la posición 0º
    servoMotor.write(0);
    //delay(2000);
  } else {
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    // Desplazamos a la posición 90º
    servoMotor.write(90);
    //delay(2000);
  }
  Serial.println(lectura);
  delay(10); // Delay a little bit to improve simulation performance
}
