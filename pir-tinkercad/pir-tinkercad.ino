void setup()
{
  pinMode(6, INPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);

}

void loop()
{
  if (digitalRead(6) == HIGH) {
    digitalWrite(4, HIGH);
    Serial.println("Movimiento detectado");
  } else {
    digitalWrite(4, LOW);
    Serial.println("Movimiento detenido");
  }
  delay(10); // Delay a little bit to improve simulation performance
}