int m1a = 10;            //Motor 1, pin 10 del arduino va al pin 15 del L293B.
int m1b = 9;             //Motor 1, pin 9 del arduino va al pin 10 del L293B.
int m2a = 12;            //Motor 2, pin 12 DEL arduino va al pin 2 del L293B.
int m2b = 11;            //Motor 2, pin 11 del arduino va al pin 7 del L293B.
int led1 = 8;            // led1 conectado al pin 8 luz delantera
int led2 = 7;            // led2 conectado al pin 7 luz delantera
int led3 = 6;            // led3 conectado al pin 6 luz frenos
int led4 = 5;            // led4 conectado al pin 5 luz frenos
int led5 = 2;            // led5 conectado al pin 4 luz trasera
int led6 = 3;            // led6 conectado al pin 3 luz trasera
int buzzer =2;          //buzzer conectado al pin 2
int contador1 = 0;
int contador2 = 0;
char val;

void setup(){  
pinMode(m1a, OUTPUT);  // Digital pin 10 set as output Pin
pinMode(m1b, OUTPUT);  // Digital pin 9 set as output Pin
pinMode(m2a, OUTPUT);  // Digital pin 12 set as output Pin
pinMode(m2b, OUTPUT);  // Digital pin 11 set as output Pin
pinMode(led1,OUTPUT);  // led1 conectado como salida
pinMode(led2,OUTPUT);   // led2 conectado como salida
pinMode(led3,OUTPUT);   // led3 conectado como salida
pinMode(led4,OUTPUT);   // led4 conectado como salida
pinMode(buzzer,OUTPUT);   // led4 conectado como salida
Serial.begin(9600);
}

void loop(){
  while (Serial.available() > 0)
  {
  val = Serial.read();
  Serial.println(val);

  if( val == 'F')                   // Hacia adelante
  {
   digitalWrite(m1a, HIGH);
      digitalWrite(m1b, LOW);
      digitalWrite(m2a, HIGH);
      digitalWrite(m2b, LOW);  
    }

  else if(val == 'B')              // Hacia atras
    {
      digitalWrite(m1a, LOW);
      digitalWrite(m1b, HIGH);
      digitalWrite(m2a, LOW);
      digitalWrite(m2b, HIGH);
    }

    else if(val == 'L')             // Izquierda
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, HIGH);
    digitalWrite(m2b, LOW);
    }

    else if(val == 'R')              //Derecha
    {
    digitalWrite(m1a, HIGH);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);

    }
      else if(val == 'S')               //Stop - Pare, Carrito detenido
    {
    digitalWrite(m1a, LOW);
    digitalWrite(m1b, LOW);
    digitalWrite(m2a, LOW);
    digitalWrite(m2b, LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    }
if(val== 'A' )            //ENCENDER LAS LUCES
{
contador1++;
Serial.println(contador1);
}

if(val== 'Z' )            //activar el buzzer
{
contador2++;
Serial.println(contador2);
}
if(val == 'U'){
  tone(buzzer,1500);
  delay(100);
  noTone(buzzer);
  delay(50);
  tone(buzzer,1000);
  delay(50);
  noTone(buzzer);
  delay(50);
  tone(buzzer,500);
  delay(50);
  noTone(buzzer);
  delay(50);
  tone(buzzer,200);
  delay(50);
  noTone(buzzer);
  delay(50);
  tone(buzzer,100);
  delay(50);
  noTone(buzzer);
  delay(50);
  tone(buzzer,50);
  delay(50);
  noTone(buzzer);
}
if(contador1 == 1){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led5,HIGH);
  digitalWrite(led6,HIGH);
}
if(contador1 == 2){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);
  contador1 = 0;
}
if(contador2 == 1){
  tone(buzzer,700);
}
if(contador2 == 2){
  noTone(buzzer);
  contador2 = 0;
}
}
}