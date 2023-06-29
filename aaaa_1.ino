#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include <LedControl.h>
#define esperar 300

LedControl MATLED = LedControl(3,5,4,1); // crea objeto
Adafruit_NeoPixel pixels (7,7);
Adafruit_NeoPixel mdf (7,6);
Servo servo;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
char letra;
int numero;
char d1;
char d2;
char d3;
char d4;
int contador = 0;
int contador1 = 0;
int contador2 = 0;
int contador3 = 0;
int contador4 = 0;
int contador5 = 0;
int contador6 = 0;
int contador7 = 0;
int contador8 = 0;
int contador9 = 0;
byte figura1[8] = {
  0x7e, 0x24, 0x18, 0x24, 0x42, 0xff, 0xff, 0x7e
};

byte figura2[8] = {
  0xdb, 0x5a, 0x3c, 0x18, 0x18, 0x3c, 0x66, 0xe7
};

byte figura3[8] = {
  0x3c, 0x42, 0x99, 0x81, 0xa5, 0x99, 0x42, 0x3c
};

void setup() {

  Serial.begin(9600);
  pixels.begin();
  servo.attach(8);
  MATLED.shutdown(0,false);     // enciende la matriz
  MATLED.setIntensity(0,10);      // establece brillo
  MATLED.clearDisplay(0);     // blanquea matriz
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  }



void loop() {

  if (Serial.available() > 0) {

    letra = Serial.read();
    numero = Serial.read();
    Serial.println(letra);
    switch (letra) {

      case 'a':
        contador++;
           Serial.println(contador);
        break;
           case 'b':
        contador1++;
        break;
      case 'c':
        contador2++;
        break;
      case 'd':
        contador3++;
           Serial.println(letra);
              Serial.println(contador3);
        break;
      case 'e':
        contador4++;
        break;
      case 'f':
        contador5++;
        break;
      case 'g':
        contador6++;
        break; 
      case 'h':
        contador7++;
        break; 
      case 'z':
        contador8++;
        break;
    }

 if(contador == 1){
   digitalWrite(led1,HIGH);  
    Serial.println(contador);
  }
 if(contador == 2){
   digitalWrite(led1,LOW);
   contador = contador-contador;
  }

   if(contador1 == 1){
   digitalWrite(led2,HIGH);
  }
 if(contador1 == 2){
   digitalWrite(led2,LOW);
   contador1 = contador1-contador1;
  }
   if(contador2 == 1){
   digitalWrite(led3,HIGH);
  }
 if(contador2 == 2){
   digitalWrite(led3,LOW);
   contador2 = contador2-contador2;
  }
   if(contador3 == 1){
   digitalWrite(led4,HIGH);
  }
 if(contador3 == 2){
   digitalWrite(led4,LOW);
   contador3 = contador3-contador3;
  }

  if(contador4 == 1){
 for(int i = 0; i < 8; i++){
   MATLED.setRow(0,i,figura1[i]);
 }
  }
if(contador4 == 2){
  contador4 = contador4-contador4;
  MATLED.clearDisplay(0);
}
  if(contador5 == 1){
 for(int i = 0; i < 8; i++){
   MATLED.setRow(0,i,figura2[i]);
 }
  }
if(contador5 == 2){
  contador5 = contador5-contador5;
    MATLED.clearDisplay(0);

}
  if(contador6 == 1){
 for(int i = 0; i < 8; i++){
   MATLED.setRow(0,i,figura3[i]);
 }
  }
if(contador6 == 2){
  contador6 = contador6-contador6;
    MATLED.clearDisplay(0);

}
if(contador7 == 1){
    pixels.clear();
     pixels.setPixelColor(6, pixels.Color(150, 0, 0));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(3, pixels.Color(0, 150, 0));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(2, pixels.Color(0, 0, 150));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(1, pixels.Color(150, 0, 150));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(5, pixels.Color(150, 200, 150));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(4, pixels.Color(0, 150, 150));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(0, pixels.Color(150, 200, 0));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(2, pixels.Color(150, 100, 30));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(3, pixels.Color(150, 0, 200));
  pixels.show();
  delay(esperar);
        pixels.setPixelColor(4, pixels.Color(150, 100, 175));
  pixels.show();
  delay(esperar);
  pixels.clear();
}
if(contador7 ==2){
  pixels.clear();
  
  contador7 = contador7-contador7;
}
if(contador8 == 1){
  digitalWrite(led2,HIGH);
  digitalWrite(led1,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
}
if(contador8 == 2){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
contador8 = 0;
}
if(char lol = Serial.read() > '0'){
  servo.write(lol);
}

}
}