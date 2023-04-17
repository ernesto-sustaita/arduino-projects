int pinLed[5] = {5,7,9,11,13};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i <5; i++){
    pinMode(pinLed[i], OUTPUT);
    digitalWrite(pinLed[i], LOW);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int p = 2; p < 7; p++){
    digitalWrite(p, HIGH);
    if(p>2){
      digitalWrite(p-1, LOW);
     }
     delay(300);
  }
  for(int p = 5; p > 2; p--){
    digitalWrite(p, HIGH);
    digitalWrite(p+1, LOW);
    delay(300);
  }
}
