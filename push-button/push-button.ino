int contador = 0;

void setup() {
   pinMode(7, INPUT_PULLUP);  //Declarar el pin 7 como entrada con pull-up
   Serial.begin(9600); // Iniciar el puerto serial a 9600 BAUDs

}

void loop() {

  //Leer el estado de la entrada digital 7
  int estadoBoton = digitalRead(7); 
  //Serial.println(estadoBoton);
  
  if(estadoBoton == 0){
    //El boton esta activado
    contador++;
    Serial.print("Boton activado: ");
    Serial.println(contador);
  }
  else{
    contador=0;
    //El boton esta desactivado
   // Serial.println("Boton desactivado");
  }

}
