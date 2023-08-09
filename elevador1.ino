#include <Stepper.h>
#include <LedControl.h>

int boton2 = 3;
int boton3 = 4;
int boton1 = 2;
int val1;
int val2;
int val3;
bool piso1 = 1;
bool piso2 = 0;
bool piso3 = 0;

//////
int piso_1 = 0;
int piso_2 = 0;
const int rotacionc = 2048;
byte numero1[8] = {//programar la figura
0x7e, 0x7e, 0x18, 0x18, 0x18, 0x1c, 0x18, 0x0
};
byte numero2[8] = {//programar la figura
0x7c, 0x8, 0x10, 0x20, 0x40, 0x44, 0x38, 0x0
};
byte numero3[8] = {//programar la figura
0x38, 0x44, 0x40, 0x38, 0x40, 0x44, 0x38, 0x0
};
byte numero4[8] = {//programar la figura
0x0, 0x3c, 0x81, 0x0, 0x24, 0x0, 0x18, 0x0
};
const float velocidad = 0.0343;
float time;
float distancia;
/////
Stepper motor = Stepper(2048,8, 10, 9, 11);
LedControl matriz = LedControl(5,7,6,1);

void setup() {

  motor.setSpeed(15);
  Serial.begin(9600);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  pinMode(boton1,INPUT);
  matriz.shutdown(0,false);     // enciende la matriz
  matriz.setIntensity(0,12);      // establece brillo
  matriz.clearDisplay(0);     // blanquea matriz
}

void loop() {

Serial.println("HAPPY");
val1 = digitalRead(boton1);
val2 = digitalRead(boton2);
val3 = digitalRead(boton3);
Serial.println(val1);
Serial.println(val2);
Serial.println(val3);

if(piso1 == 1){
  mostrarnum1();
if(val2 == 1){
  motor.step(-10100);
  mostrarnum2();
  piso2 = 1;
  piso1 = 0;
}
if(val3 == 1){
  motor.step(-20200);
  mostrarnum3();
  piso3 =1;
  piso1 =0;
}
}

if(piso2 ==1){
  mostrarnum2();
if(val1 == 1){
  motor.step(10100);
  mostrarnum1();
  piso1 =1;
  piso2=0;
}
if(val3 ==1){
  motor.step(-10100);
  mostrarnum3();
  piso3 = 1;
  piso2 = 0;
}
}

if(piso3 ==1){
  mostrarnum3();
if(val2 == 1){
  motor.step(10100);
  mostrarnum1();
  piso2 =1;
  piso3=0;
}
if(val1 ==1){
  motor.step(20200);
  mostrarnum3();
  piso1 = 1;
  piso3 = 0;
}
}



// if(val1 == 1){
//   motor.step(-20200);
//   mostrarnum1();
// }

// if(val2 == 1){
//   motor.step(10100);
//   mostrarnum2();
// }

// if(val3 == 1){
//   motor.step(20200);
//   mostrarnum3();
// }



}

void mostrarnum1(){// fucion sin retorno
     for(int i = 0; i < 8; i++){
   matriz.setRow(0,i,numero1[i]);
 }
}
void mostrarnum2(){// fucion sin retorno
     for(int i = 0; i < 8; i++){
   matriz.setRow(0,i,numero2[i]);
 }
}
void mostrarnum3(){// fucion sin retorno
     for(int i = 0; i < 8; i++){
   matriz.setRow(0,i,numero3[i]);
 }
}
void mostrarnum4(){// fucion sin retorno
     for(int i = 0; i < 8; i++){
   matriz.setRow(0,i,numero4[i]);
 }
}
