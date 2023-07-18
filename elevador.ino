#include <Stepper.h>
#define Trig 4
#define echo 5
int boton2 = 8;
int boton3 = 9;
int boton1 = 10;
//////
int piso_1 = 0;
int piso_2 = 0;
const int rotacionc = 2048;
const float velocidad = 0.0343;
float time;
float distancia;
/////
Stepper motor = Stepper(rotacionc, 8, 10, 9, 11);

void setup() {
  pinMode(Trig,OUTPUT);
  pinMode(echo,INPUT);
  motor.setSpeed(10);
  Serial.begin(9600);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  pinMode(boton1,INPUT);
}

void loop() {
medida();
Serial.println(distancia);
Serial.println("todotranqui");
//distancia = 2
//distancia = 15
if(distancia > 5 && distancia < 10 ){//si el elevador esta en el piso 3
  if(boton1 == 1){
motor.step(-4096);//baja dos pisos
  }
  if(boton2 == 1){
motor.step(-2048);//baja un pisos
  }  
}
if(distancia > 10 && distancia < 30 ){//si el elevador esta en el piso 2
  if(boton1 == 1){
motor.step(-2048);//baja un piso
  }
  if(boton3 == 1){
motor.step(2048);//sube un piso
  }
}
if(distancia > 30 && distancia < 42){//si el elevador esta en el piso 1
  if(boton2 == 1){
motor.step(2048);//sube un piso
  }
  if(boton3 == 1){
motor.step(4096);//sube dos pisos
  }
}

}



void medida(){
digitalWrite(Trig, HIGH);
delay(1);
digitalWrite(Trig, LOW);
time = pulseIn(echo, HIGH);
distancia = (time)*velocidad/2;
}