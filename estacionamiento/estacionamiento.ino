#include <Servo.h>

long tiempo0 = 0;
long tiempo1 = 0;
long tiempo2 = 0;
long tiempo3 = 0;
bool primeraVezEntrada = true;
bool primeraVezSalida = true;
long distanciaEntrada = 0;
long distanciaSalida = 0;
long distanciaCajon1 = 0;
long distanciaCajon2 = 0;
long distanciaCajon3 = 0;
int disponibilidadCajones = 0;

Servo servo_entrada;
Servo servo_salida;

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
  //distanciaEntrada = 0.01723 * readUltrasonicDistance(26, 27);

  // Si se detecta que el botón está presionado y el vehículo está presente...
  //if (digitalRead(29) == 0 && distanciaEntrada < 20) { // 5 es el pin del push button de entrada
  if (digitalRead(8) == 0){  
    if(primeraVezEntrada){
        delay(1000);
        servo_entrada.write(90); // Open the access
        primeraVezEntrada = false;
        tiempo0 = millis();  // Tiempo del botón presionado
    }
  } else {

    
    if(primeraVezEntrada == false){
      //if(distanciaEntrada <= 20){
        //tiempo0 = millis();  // Tiempo del botón presionado, pero el vehículo sigue ahí
      //}else{
        tiempo1 = millis();  // Establecer tiempo de cuando ya no se detecta el vehículo
      //}

      // Si el tiempo en el que se dejó de detectar el vehículo supera los 3 segundos, cerramos la puerta
      if((tiempo1 - tiempo0) > 5000){
        servo_entrada.write(0);
        primeraVezEntrada = true;
      }
    }
  }  
}

void abrirPuertaSalida()
{
  //distanciaSalida = 0.01723 * readUltrasonicDistance(24, 25);

  // Si se detecta que el botón está presionado y el vehículo está presente...
  //if (digitalRead(28) == 0 && distanciaSalida < 20) { // 0 es el pin del push button de salida
  if (digitalRead(9) == 0){  
    if(primeraVezSalida){
        delay(1000);
        servo_salida.write(90); // Open the access
        primeraVezSalida = false;
        tiempo2 = millis();  // Tiempo del botón presionado
    }
  } else {
    
    if(primeraVezSalida == false){
      //if(distanciaSalida <= 20){
        //tiempo2 = millis();  // Tiempo del botón presionado, pero el vehículo sigue ahí
      //}else{
        tiempo3 = millis();  // Establecer tiempo de cuando ya no se detecta el vehículo
      //}

      // Si el tiempo en el que se dejó de detectar el vehículo supera los 3 segundos, cerramos la puerta
      if((tiempo3 - tiempo2) > 5000){
        servo_salida.write(180);
        primeraVezSalida = true;
      }
    }
  }  
}

int verificarDisponibilidad()
{
  distanciaCajon1 = 0.01723 * readUltrasonicDistance(22, 23);
  distanciaCajon2 = 0.01723 * readUltrasonicDistance(26, 27);
  distanciaCajon3 = 0.01723 * readUltrasonicDistance(30, 31);
  
  disponibilidadCajones = 3;

  if(distanciaCajon1 < 20){ // Cajón 1 ocupado
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH); // Encender LED rojo
  }else{
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH); // Encender el LED verde
    disponibilidadCajones += 1;
  }
  if(distanciaCajon2 < 20){ // Cajón 2 ocupado
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH); // Encender LED rojo
  }else{
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH); // Encender el LED verde 
    disponibilidadCajones += 1;
  }
  if(distanciaCajon3 < 20){ // Cajón 3 ocupado
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH); // Encender LED rojo
  }else{
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH); // Encender el LED verde   
    disponibilidadCajones += 1;
  }

  Serial.println(disponibilidadCajones); // Mandamos al puerto serial para que lo reciba la Raspberry
}

void setup()
{
  // Establecer pines
  pinMode(8, INPUT); // Push button de entrada
  pinMode(9, INPUT); // Push button de salida
  pinMode(7, OUTPUT); // LED disponibilidad cajón 1
  pinMode(6, OUTPUT); // LED disponibilidad cajón 1
  pinMode(5, OUTPUT); // LED disponibilidad cajón 2
  pinMode(4, OUTPUT); // LED disponibilidad cajón 2
  pinMode(3, OUTPUT); // LED disponibilidad cajón 3
  pinMode(2, OUTPUT); // LED disponibilidad cajón 3
  digitalWrite(8, HIGH); // Mandar señal a Push Button
  digitalWrite(9, HIGH); // Mandar señal a Push Button
  // Motor servo para la entrada
  servo_entrada.attach(36);
  servo_salida.attach(40);

  Serial.begin(9600);
}

void loop()
{
  abrirPuertaEntrada();
  abrirPuertaSalida();
  verificarDisponibilidad();
}
