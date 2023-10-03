const int volti_ampi = A0;   // seleccionar la entrada para el sensor
const int ampi = A1;   // seleccionar la entrada para el sensor
int entrada;      // variable que almacena el valor raw (0 a 1023)
int entrada1;      // variable que almacena el valor raw (0 a 1023)
float volt;        // variable que almacena el voltaje (0.0 a 25.0)
float Sensibilidad=0.185; //sensibilidad en Voltios/Amperio para sensor de 5A
int contador = 0;
int botonResist = 4;
  int   Pin_de_medicion = 5; // Pin analogico 5
  int   R1 = 1000; // Cambiar por el valor de la resistencia conocida (Resistencia de clibracion)
  long  lectura; // Lectura en el pin analogico 5
  float Tension_de_trabajo = 5.0; // VCC 
  float Voltaje_R2; // Valor que calculamos
  float Resistencia; // Valor que calculamos

void setup() {
  Serial.begin(9600);
  pinMode(botonResist,INPUT);
  attachInterrupt(digitalPinToInterrupt(2),voltimetro,RISING);
  attachInterrupt(digitalPinToInterrupt(3),amperimetro, RISING);
}

void loop() {
  if(botonResist == 1){
contador = 3;
}
  entrada = analogRead(volti_ampi);        // realizar la lectura
  entrada1 = analogRead(ampi);        // realizar la lectura

if(contador == 1){
  volt = (entrada - 0) * (25.0 - 0.0) / (1023 - 0) + 0.0;   // cambiar escala a 0.0 - 25.0
  Serial.println(volt); 
}
if(contador == 2){
  float voltajeSensor= entrada1*(5.0 / 1023.0); //lectura del sensor   
  float I=(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  Serial.print("Corriente: ");
  Serial.println(I,3);
}
  if(contador == 3){
  ohimetro;
  }
}

void voltimetro(){
contador = 1;
}
void amperimetro(){
contador = 2;
}


 void ohimetro(){
      // Leemos el valor en el pin A5
  lectura=0;
  for(int i=0;i<5;i++){
    lectura+=analogRead(Pin_de_medicion);
  }
  lectura=trunc(lectura/5);
  
  // Colculamos el voltaje en la resistencia desconocida
  Voltaje_R2=(Tension_de_trabajo/1023.0)*lectura;
  
  // Lo imprimimos en el Monitor Serie
  Serial.print("Voltaje en R2: ");
  Serial.print(Voltaje_R2,2);
  Serial.println(" Voltios");
  
  //Calculamos la resistencia desconocida con las fórmulas
  // (V1/R1=V2/R2) y (V1=+5V-V2)
  Resistencia=R1*Voltaje_R2/(Tension_de_trabajo-Voltaje_R2);
  Serial.print("La resistencia tiene ");
  Serial.print(Resistencia,2);
  Serial.println(" Ohm.");
  Serial.println();
  delay(5000);
  }
