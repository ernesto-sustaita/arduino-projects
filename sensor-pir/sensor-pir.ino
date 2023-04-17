int led = 13;
int sensor = 2;
int state = LOW;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);
  if(val == HIGH){
    digitalWrite(led, HIGH);
    delay(100);

    if(state == LOW){
      Serial.println("Movimiento detectado");
      state = HIGH;
      }
    }
    else {
      digitalWrite(led, LOW);
      delay(200);

      if(state == HIGH){
        Serial.println("El movimiento se detuvo");
        state = LOW;
        }
      }
}
