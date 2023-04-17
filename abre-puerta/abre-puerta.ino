#include <Servo.h>

long tiempo0 = 0;
long tiempo1 = 0;
bool primeraVez = true;
long distancia = 0;

Servo servo_entrada;

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

void abrirPuertaEntrada()
{
  distancia = 0.01723 * readUltrasonicDistance(2, 3);

  // Si se detecta que el botón está presionado y el vehículo está presente...
  if (digitalRead(5) == 0 && distancia < 20) {
    if(primeraVez){
        servo_entrada.write(90); // Open the access
        primeraVez = false;
    }
  } else {
    
    if(primeraVez == false){
      if(distancia <= 20){
        tiempo0 = millis();  // Tiempo del botón presionado, pero el vehículo sigue ahí
      }else{
        tiempo1 = millis();  // Establecer tiempo de cuando ya no se detecta el vehículo
      }

      // Si el tiempo en el que se dejó de detectar el vehículo supera los 3 segundos, cerramos la puerta
      if((tiempo1 - tiempo0) > 3000){
        servo_entrada.write(0);
        primeraVez = true;
      }
    }
  }  
}

void setup()
{
  // Establecer pines
  pinMode(5, INPUT);
  digitalWrite(5, HIGH);
  // Motor servo para la entrada
  servo_entrada.attach(4);

  Serial.begin(9600);
}

void loop()
{
  abrirPuertaEntrada();

  
}
