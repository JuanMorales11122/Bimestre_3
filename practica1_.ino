#include <LiquidCrystal_I2C.h>
#define TRIG 8
#define ECHO 9
#define bombba 4

const float VELOCIDAD = 0.0343;
float TIME;
float DISTANCIA;
LiquidCrystal_I2C pantalla(0x27, 16, 2);
int pinBuzzer = 6;


//De la cancion
int C_ =  261/2;
int Cs_=  277/2;
int D_ =  293/2 ;
int Ds_=  311/2;
int E_ =  329/2 ;
int F_ =  349/2 ;
int Fs_=  369/2;
int G_ =  391/2 ;
int Gs_=  415/2;
int A_ =  440/2 ;
int As_=  466/2;
int B_ =  493/2 ;
int Sil = 5;
int C =  261;
int Cs=  277;
int D =  293 ;
int Ds=  311;
int E =  329 ;
int F =  349 ;
int Fs=  369;
int G =  391 ;
int Gs=  415;
int A =  440 ;
int As=  466;
int B =  493 ;
int C2   =524;
int Cs2  =555;
int D2   =588;
int Ds2  =623;
int E2   =660;
int F2   =699;
int Fs2  =740;
int G2   =784;
int Gs2  =831;
int A_2   = 880;
int As2  =933;
int B2   =988;
int C3  =1047;
int Cs3  =555*2;
int D3   =588*2;
int Ds3  =623*2;
int E3   =660*2;
int F3   =699*2;
int Fs3  =740*2;
int G3   =784*2;
int Gs3  =831*2;
int A_3   = 880*2;
int As3  =933*2;
int B3   =988*2;
int tempo=112*2;
int negra=60000/tempo;
int semi = negra/4;
//int semi =86;
int corch = 2*semi;
//int negra = corch*2;
int np = corch*3;
int blanca = negra*2;
int redonda = blanca*2;
int rep = 3*negra;
int bnp = 3*negra+3*corch;
int retardo = 100;
void nota(int nota, int duracion){
  tone(pinBuzzer,nota, duracion);
  delay(duracion);
  noTone(pinBuzzer);
  delay(duracion);
}
//fin del programa de la cancion


  
void setup()
{
  pinMode(pinBuzzer,OUTPUT);
Serial.begin(9600);
pinMode(TRIG,OUTPUT);
pinMode(ECHO,INPUT);
pinMode(bombba,OUTPUT);
pantalla.init();
pantalla.backlight();
pantalla.clear();
attachInterrupt(digitalPinToInterrupt(2),llenar,CHANGE);
attachInterrupt(digitalPinToInterrupt(3),pausa,HIGH);
}

void loop()
{

digitalWrite(TRIG,HIGH);
delay(1);
digitalWrite(TRIG,LOW);
TIME = pulseIn(ECHO,HIGH);
DISTANCIA = (TIME)*VELOCIDAD/2;
Serial.println(DISTANCIA);
delay(200);
if(DISTANCIA >=13){
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("15%");
  }
if(DISTANCIA >=12 && DISTANCIA<13){
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("29%");
  }
if(DISTANCIA >=11 && DISTANCIA<12){
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("43%");
  }
if(DISTANCIA >=10 && DISTANCIA<11){
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("57%");
  }
if(DISTANCIA >=9 && DISTANCIA<10){
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("71%");
  }
  if(DISTANCIA >=8 && DISTANCIA<9){
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("85%");
  }
    if(DISTANCIA >=7 && DISTANCIA<8){
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("92%");
  }
    if(DISTANCIA >=6&& DISTANCIA<7){
  pantalla.clear();
  pantalla.setCursor(0, 0);
  pantalla.print("100%");

  }
}

void llenar(){
digitalWrite(bombba,LOW);
tone(pinBuzzer,200);
}

void pausa(){
digitalWrite(bombba,HIGH);
noTone(pinBuzzer);
  }





  //de la cancion tambien
  void prePre(){
  nota(A   , semi );
  nota(A_   , semi );
  nota(C2  , semi);  
  nota(A_   , semi );
  nota(B   , semi );
  nota(A_   , semi );
  nota(C2  , semi);  
  nota(E2 , semi);  
  nota(A_   , semi );
  nota(A   , semi );
  nota(C2  , semi);  
  nota(A_   , semi );
  nota(B   , semi );
  nota(Sil , semi);  
  nota(C2  , semi);  
  nota(A   , semi );
  nota(A_   , semi );
  nota(A   , semi );
  nota(C2   , semi );
  nota(A_   , semi );
  nota(B   , semi );
  nota(A_   , semi );
  nota(C2   , semi );
  nota(E2   , semi );
  nota(A_   , semi );
  nota(A   , semi );
  nota(C2   , semi );
  nota(A_   , semi );
  nota(B   , semi );
  nota(A_   , semi );
  nota(C2   , semi );
 nota(A_   , semi );
}
void uno_(){
  nota(E   , semi );
  nota(E_   , semi );
  nota(G   , semi );
  nota(E_   , semi );
  nota(Fs   , semi );
  nota(E_   , semi );
  nota(G   , semi );
  nota(B   , semi );
  nota(E_   , semi );
  nota(E   , semi );
  nota(G   , semi );
  nota(E_   , semi );
  nota(Fs   , semi );
  nota(E_   , semi );
  nota(G   , semi );
  nota(E   , semi );
  nota(E_   , semi );
  nota(E   , semi );
  nota(G   , semi );
  nota(E_   , semi );
  nota(Fs   , semi );
  nota(E_   , semi );
  nota(G   , semi );
  nota(B   , semi );
  nota(E_   , semi );
  nota(E   , semi );
  nota(G   , semi );
  nota(E_   , semi );
  nota(Fs   , semi );
  nota(E_   , semi );
  nota(G   , semi );
  nota(E_   , semi ); 
}
void dos_(){
  nota( F  , semi );
  nota( F_ , semi );
  nota( A  , semi );
  nota( F_ , semi );
  nota(G , semi);
  nota(F_, semi);
  nota(A , semi);
  nota(C2, semi);
  nota( F_ , semi );
  nota( F  , semi );
  nota( A  , semi );
  nota( F_ , semi );
  nota( G, semi);
  nota( F_ , semi );
  nota( A  , corch );
    nota(G , semi);
    nota(G_ , semi);
    nota(B , semi);
    nota(G_ , semi);
    nota(A , semi);
    nota(G_ , semi);
    nota(B , semi);   
    nota(D2 , semi);
    nota(G_ , semi);
    nota(G , semi);
    nota(B , semi);
    nota(G_ , semi);
    nota(A , semi);
    nota(G_ , semi);
    nota(B , corch);
}
void tres(){
  nota(D , semi);
  nota(D_ , semi);
  nota(F , semi);
  nota(D_ , semi);
  nota(E , semi);
  nota(D_ , semi);
  nota(F , semi);
  nota(A , semi);
  nota(D_ , semi);
  nota(D , semi);
  nota(F , semi);
  nota(D_ , semi);
  nota(E , semi);
  nota(D_ , semi);
  nota(F , corch);
}
void cuatro(){
  nota(E , semi);
  nota(E_ , semi);
  nota(G , semi);
  nota(E_ , semi);
  nota(Fs , semi);
  nota(E_ , semi);
  nota(G , semi);
  nota(B , semi);
  nota(E_ , semi);
  nota(E , semi);
  nota(G , semi);
  nota(E_ , semi);
  nota(Fs , semi);
  nota(E_ , semi);
  nota(G , corch);
  }