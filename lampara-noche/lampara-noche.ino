const int relay = 2;
const int ldr = A0;
const int pir = 4;
const int threshold = 100;
int val = 0;
bool state = LOW;

void setup() {
  //Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(relay,OUTPUT);
  pinMode(ldr,INPUT);
  pinMode(pir,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int input = analogRead(ldr);
  if(input<threshold){
    //Serial.println("Está oscuro");
    val = digitalRead(pir);
    if(val == HIGH){
      digitalWrite(relay,HIGH);
      delay(12000);
  
      if(state == LOW){
        //Serial.println("¡Movimiento detectado!");
        state = HIGH;
      }
    }else{
      digitalWrite(relay,LOW);
      //delay(5000);
  
      if(state == HIGH){
        //Serial.println("¡Movimiento detenido!");
        state = LOW;
      }
    }
    //delay(100);
  }else{
    //Serial.println("Hay luz");
    digitalWrite(relay,LOW);
    delay(100);
  }
  //delay(500);
}
