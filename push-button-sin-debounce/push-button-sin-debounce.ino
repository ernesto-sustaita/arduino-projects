#include <Servo.h>
int lectura = 0;
// Declaramos la variable para controlar el servo
Servo servoMotor;
int contador = 0;
unsigned long tiempo0 = 0;
unsigned long tiempo1 = 0;
bool primeraVez = false;
unsigned long cierra0 = 0;
unsigned long cierra1 = 0;

long readUltrasonicDistance(int triggerPin, int echoPin){
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

void setup() {
   pinMode(7, INPUT_PULLUP);  //Declarar el pin 7 como entrada con pull-up
   servoMotor.attach(9);
   Serial.begin(9600); // Iniciar el puerto serial a 9600 BAUDs

}

void loop() {

  lectura = 0.01723 * readUltrasonicDistance(2, 3);
  
  //Leer el estado de la entrada digital 7
  int estadoBoton = digitalRead(7); 
  Serial.println(estadoBoton);
  
  if(estadoBoton == 0){
    //El boton esta activado
    Serial.print("Primer IF");
    if(!primeraVez){ 
      //Se detecta la primera activacion y se guarda ese tiempo
      primeraVez = true; 
      tiempo0 = millis(); 
      Serial.print("IF primera vez");
      servoMotor.write(90);
    }  
    else{
      tiempo1 = millis();     //En los rebotes se verifica el tiempo, aqui se podria llamar a otra funcion para aprovechar el tiempo del procesador
      if((tiempo1-tiempo0)>200) {  //Si el tiempo supera los 200ms entonces activamos las instrucciones correspondientes
          //Se activo el boton y pasaron 200ms
          primeraVez = false;
          contador++;
          Serial.print("Boton activado: ");
          Serial.println(contador);
          // Desplazamos a la posición 90º
          servoMotor.write(90);
          //tiempo0 = millis();
      }
    }   
  }
  else{
    contador=0;

      tiempo1 = millis(); //500

      Serial.print("Tiempo 1: ");
      Serial.print(tiempo1);
      
      if (lectura > 20) {

        if((tiempo1 - tiempo0) > 500){ // 500 - 0 = 500
          servoMotor.write(0);
        }
        // Desplazamos a la posición 0º
        
        //El boton esta desactivado
       Serial.println("Boton desactivado");
      }else{
        tiempo0 = millis();

        Serial.print("Tiempo 0: ");
        Serial.println(tiempo0);
        }
  }

  //delay(1000);
}
