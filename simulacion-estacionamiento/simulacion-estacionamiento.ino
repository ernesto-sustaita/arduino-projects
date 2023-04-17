 
void setup() {
  // PREPARAR LA COMUNICACION SERIAL
  Serial.begin(9600);
}
 
void loop() {
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(random(9));
  delay(1000);
}
