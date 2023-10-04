#include <SoftwareSerial.h>

float input_volt = 0.0;
float temp=0.0;
float r111=10000.0;    //r1 valor
float r222=100000.0;      //r2 valor
const int ampi = A1;   // seleccionar la entrada para el sensor
int entrada1;      // variable que almacena el valor raw (0 a 1023)
float volt;        // variable que almacena el voltaje (0.0 a 25.0)
float Sensibilidad=0.185; //sensibilidad en Voltios/Amperio para sensor de 5A
int contador = 0;
int botonResist = 6;
int voltimetro = 4;
int amperimetro = 5;

int sensorPin = A5;
int valorSensor;
float voltaje, r1, r2;

SoftwareSerial hc06(2,3);
void setup() {
  Serial.begin(9600);
  pinMode(botonResist,INPUT);
  pinMode(voltimetro,INPUT);
pinMode(amperimetro,INPUT);
  r2 = 10000; // R2 = 10KΩ
}

void loop() {

 int ohmi = digitalRead(botonResist);
int volti = digitalRead(voltimetro);
int ampi = digitalRead(amperimetro);
  if(ohmi == 1){
contador = 3;
}
if(volti == 1){
contador = 1;
}
if(ampi == 1){
  contador = 2;
}
    int analogvalue = analogRead(A0);
    temp = (analogvalue * 5.0) / 1024.0;       // 
    input_volt = temp / (r222/(r111+r222));
  entrada1 = analogRead(ampi);        // realizar la lectura

if(contador == 1){
if (input_volt < 0.1) 
   {
     input_volt=0.0;
   } 
    Serial.print(input_volt);
    hc06.write(input_volt);

}
if(contador == 2){
  float voltajeSensor= entrada1*(5.0 / 1023.0); //lectura del sensor   
  float I=(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  Serial.print(I,3);
  hc06.print(I,3);
}
  if(contador == 3){
  valorSensor= analogRead(sensorPin); // Lee el valor del pin analogico A0
voltaje = (valorSensor*5.0/1023.0); // Calcula el voltaje
r1 = (voltaje*r2)/(5-voltaje);
Serial.print(r1);
hc06.print(r1);

  }
}

