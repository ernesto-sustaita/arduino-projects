int val = 0;
bool state = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(4,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(4);
  if(val == HIGH){
    digitalWrite(13, HIGH);
    delay(200);

    if(state == LOW){
      Serial.println("¡Movimiento detectado!");
      state = HIGH;
    }
  }else{
    digitalWrite(13,LOW);
    delay(200);

    if(state == HIGH){
      Serial.println("¡Movimiento detenido!");
      state = LOW;
    }
  }
}
