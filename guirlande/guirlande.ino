int pinLed[5] = {5,7,9,11,13};

boolean affichage[25][5]={
  0,0,0,0,0,
  0,0,0,0,1,
  0,0,0,1,0,
  0,0,1,0,0,
  0,1,0,0,0,
  1,0,0,0,0,
  0,0,0,0,0,
  1,0,0,0,0,
  0,1,0,0,0,
  0,0,1,0,0,
  0,0,0,1,0,
  0,0,0,0,1,
  0,0,0,0,0,
  1,1,1,1,1,
  1,1,1,1,0,
  1,1,1,0,0,
  1,1,0,0,0,
  1,0,0,0,0,
  0,0,0,0,0,
  1,1,1,1,1,
  0,1,1,1,1,
  0,0,1,1,1,
  0,0,0,1,1,
  0,0,0,0,1,
  0,0,0,0,0};

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i <5; i++){
    pinMode(pinLed[i], OUTPUT);
    digitalWrite(pinLed[i], LOW);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0;i < 25; i++){
    for(int p = 0; p < 5; p++){
      boolean etat = affichage[i][p];
      digitalWrite(pinLed[p], etat);
      }
      delay(300);
    }
}
