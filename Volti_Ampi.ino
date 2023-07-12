const int volti_ampi = A0;   // seleccionar la entrada para el sensor
const int ampi = A0;   // seleccionar la entrada para el sensor
int entrada;      // variable que almacena el valor raw (0 a 1023)
float volt;        // variable que almacena el voltaje (0.0 a 25.0)
float Sensibilidad=0.185; //sensibilidad en Voltios/Amperio para sensor de 5A
int contador;

void setup() {
  Serial.begin(9600);
}

void loop() {
  entrada = analogRead(volti_ampi);        // realizar la lectura

if(contador == 1){
  volt = (entrada - 0) * (25.0 - 0.0) / (1023 - 0) + 0.0;   // cambiar escala a 0.0 - 25.0
  Serial.println(volt); 
}
if(contador == 2){
  float voltajeSensor= entrada*(5.0 / 1023.0); //lectura del sensor   
  float I=(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  Serial.print("Corriente: ");
  Serial.println(I,3);
}
}

void voltimetro(){
contador = 1;
}
void amperimetro(){
contador = 2;
}



/*
// cambio de escala entre floats
float fmap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
*/