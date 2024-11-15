#include<Servo.h>

Servo Servo;
int rojo=13;
int verde=12;
void setup()
{
  pinMode(3,OUTPUT);
  pinMode(4,INPUT);
  pinMode(rojo,OUTPUT);
  pinMode(verde,OUTPUT);
  Servo.attach(6);
  digitalWrite(rojo,HIGH);
}

void loop()
{
  while(dist()>=10);{ // mientras la distancia > a 10cm
  
   Servo.write(0);   // la puerta esta cerrada
   digitalWrite(rojo,HIGH);
   digitalWrite(verde,LOW);
  }
  
  while(dist()<10);{ // mientras la distancia <= a 10cm
   
   delay(1500);      // 1.5s despues de que el auto avanza se apaga
   Servo.write(90);  // la puerta esta abierta
   digitalWrite(rojo,LOW);
    digitalWrite(verde,HIGH);
  }
}

float dist()
{

  float t; // tiempo que demora en llegar
  float d; // distancia que recorre la señal
  
  digitalWrite(3,HIGH);
  delayMicroseconds(10); // envio una señal cada 10 micro seg
  digitalWrite(3,LOW);
  
  t=pulseIn(4,HIGH); // detecta la señal 
  d=t/59;           // combierte la señal en distancia
  delay(100);      // cada cuanto abre los ojos
  return d;       // le da a mi float la distancia
  
}