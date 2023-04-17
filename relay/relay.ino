const int relay = 2;
const int ldr = A0;
const int threshold = 100;

void setup() {
  //Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(relay,OUTPUT);
  pinMode(ldr,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int input = analogRead(ldr);
  if(input<threshold){
    //Serial.println("Está oscuro");
    digitalWrite(relay,HIGH);
    //delay(100);
  }else{
    //Serial.println("Hay luz");
    digitalWrite(relay,LOW);
    //delay(100);
  }
  delay(500);
}
