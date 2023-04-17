
/**
  #HOPE SOLUTIONS
   EJEMPLO SENSOR ULTRASONICO 1
 
   REALIZA LA MEDICION DE DISTANCIA CON UN SENSOR ULTRASÓNICO HC-SR04 CONECTADO
   AL ARDUINO. ESTE EJEMPLO NO UTILIZA LIBRERIAS ESPECIALES PARA EL SENSOR, SOLAMENTE
   SE UTILIZA LA FUNCION "PULSEIN" PARA MEDIR LA LONGITUD DEL PULSO DE ECO.
 
*/
// DECLARACION DE VARIABLES PARA PINES
const int pinecho = 4;
const int pintrigger = 8;
const int pinled = 13;
 
// VARIABLES PARA CALCULOS
unsigned int tiempo, distancia;

unsigned long previousMillis = 0;
int ledState = LOW;
long interval = 0;
 
void setup() {
  // PREPARAR LA COMUNICACION SERIAL
  Serial.begin(9600);
  // CONFIGURAR PINES DE ENTRADA Y SALIDA
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  pinMode(13, OUTPUT);
}
 
void loop() {
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
 
  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);
 
  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 58;

  unsigned long currentMillis = millis();

  if(distancia > 150){
    interval = 1000;    
  }else if (distancia > 100){
    interval = 700;
    }else if (distancia > 50){
        interval = 350;
      }else if(distancia <= 15){
        interval = 100;
        }
  Serial.print(distancia);
  Serial.println(" cm");
  
  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(pinled, ledState);
  }
 
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  //Serial.print(distancia);
  //Serial.println(" cm");
  //delay(200);
 
  // ENCENDER EL LED CUANDO SE CUMPLA CON CIERTA DISTANCIA
  /*if (distancia <= 15) {
    digitalWrite(13, HIGH);
    delay(500);
  } else {
    digitalWrite(13, LOW);
  }*/
}
