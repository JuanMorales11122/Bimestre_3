

// agregamos librerias
#include <Wire.h>
#include <Servo.h>
#include <Adafuit_ADXL345.h>.
Servo servoHorizontal;
Servo servoVertical;
ADXL345 adxl;             //Declaramos nuestro acelerometro ADXL345

#define OBS 2


//DE LA CANCION
int val;
int avoid;
int pinBuzzer = 12;

int  C__ =  261/4;
int Cs__=  277/4;
int  D__ =  293/4 ;
int Ds__=  311/4;
int  E__ =  329/4 ;
int  F__ =  349/4 ;
int Fs__=  369/4;
int  G__ =  391/4 ;
int Gs__=  415/4;
int  A__ =  440/4 ;
int As__=  466/4;
int  B__ =  493/4 ;

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



int tempo=124*2;
int negra=60000/tempo;
int semi = negra/4;

int fusa =semi/2;
int corch = 2*semi;
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
//DE LA CANCION




//Declaramos variables 
int mappedRawX, mappedejeY;

void setup() { // inicializamos nuestro programa
  Serial.begin(9600);
  adxl.powerOn();
  adxl.setRangeSetting(2);
  servoHorizontal.attach(3);
  servoVertical.attach(5);
  servoHorizontal.write(90);
  servoVertical.write(90);
  esperarInicializacion();
  pinMode(pinBuzzer,OUTPUT);
     pinMode(OBS, INPUT);

}

void loop() { //lee y espera a los a servos
   val = digitalRead(OBS);
   Serial.println(val);

  leerAcelerometro();
  actualizarServos();
  milisegundos(100);

   if (val == HIGH){
    EllaDurmio();
    }

    
}

void esperarInicializacion() { // bucle de tiempo para esperar a los servos 
  delay(2000);
}
void milisegundos(int ms) {  //Esta función generaliza la espera durante un período de tiempo específico en milisegundos.
  delay(ms);
}
void leerAcelerometro() {
  int ejeX, ejeY, ejeZ;
  adxl.readAccel(&ejeX, &ejeY, &ejeZ);
  mappedRawX = map(ejeX, -255, 255, 179, 0);
  mappedejeY = map(ejeY, -255, 255, 0, 179);
}

void actualizarServos() {
  servoHorizontal.write(mappedRawX);
  servoVertical.write(mappedejeY);
}

//DE LA CANCION
void EllaDurmio(){ 


nota(B2,corch);
nota(B2,corch);
nota(A_2,corch);
nota(B2,corch+negra);
nota(G_,negra);
nota(Fs_,negra);
nota(Fs_,negra/2);

nota(A_2,corch);
nota(A_2,corch);
nota(A_2,corch);
nota(A_2,corch);


nota(B2,corch);


nota(G2,corch);
nota(Fs2,corch);
nota(E2,negra);

nota(Sil,corch);
nota(Sil,corch);

nota(G_,negra);
nota(Fs_,negra);
nota(Fs_,negra);

nota(A__,semi);
nota(A__,semi);
nota(A__,corch);
nota(A__,corch);
nota(A__,corch);

///////////7
nota(B2,corch);
nota(B2,corch);

nota(D3,corch);

nota(B2,negra);
nota(B2,corch);


nota(G_,negra);
nota(Fs_,negra);
nota(Fs_,negra/2);
nota(Sil,negra/2);

nota(A_2,corch);
nota(A_2,corch);

nota(B2,negra);


nota(G2,corch);
nota(Fs2,corch);
nota(E2,2*corch);
nota(Sil,corch);
nota(Sil,corch);

nota(G_,negra);
nota(Fs_,negra);
nota(Fs_,negra);

nota(A__,semi);
nota(A__,semi);
nota(A__,corch);
nota(A__,corch);
nota(A__,corch);


}
//DE LA CANCION
