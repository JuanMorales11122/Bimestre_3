#include <LedControl.h>
#include <TimerOne.h>
int sensor; // variable que lee el mq2
int contador = 0; //contador del mq2
int buz = 2; // pin del buzzer
LedControl matriz = LedControl(7,9,8,1);//
byte figura[8] = {//programar la figura
0x66, 0x66, 0x66, 0x66, 0x66, 0x0, 0x66, 0x66
};
void setup() {
pinMode(buz,OUTPUT);// establecer pin como salida
Serial.begin(9600);//  iniciar monitor serial
Timer1.initialize(500000);
Timer1.attachInterrupt(humo);
matriz.shutdown(0,false);     // enciende la matriz
matriz.setIntensity(0,10);      // establece brillo
matriz.clearDisplay(0);     // blanquea matriz
}

void loop() {
sensor = analogRead(A0);// lee la entrada
Serial.println(sensor);//muestra el valor que entra del mq2
if(contador == 1){// programacion que hace que todo funcione
 encenderbuz();
mostrarmatriz();
 }else{
apagar();
}
}
void humo(){// fucion sin retorno
  if(sensor > 46){
  contador = 1;
  }else{
    contador = 0;
  }
}
void apagar(){// fucion sin retorno
   matriz.clearDisplay(0);
noTone(buz);
}
void encenderbuz(){// fucion sin retorno
 tone(buz,590);
}
void mostrarmatriz(){// fucion sin retorno
     for(int i = 0; i < 8; i++){
   matriz.setRow(0,i,figura[i]);
 }
}