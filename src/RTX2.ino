#include "Adafruit_TCS34725.h"
#include <Servo.h>
#include <NewPing.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

Servo serbastian;
Servo timonteo;  //como te odio cervastian
int angGiro = 90;
int angCam = 0;  // cuanto giramos la camara
const int Trig = 2;
const int Echo = 3;
const int MaxDistance = 200;

int confA = 0; //confirmar Azul
int confN = 0; //confirmar Naranja
int confB = 0; //confirmar Blanco

int pos = 0; 

int color = 0;  //naranja - 1, azul - 2, blanco - 0
bool curva = false; //estamos en una curva?

int sentido = -1;      //la dirección (1 horario, -1 antihorario)
bool leSabe = false;  //ya sabemos la dirección?
bool goBack = false; // estamos regresando el sensor ultrasónico?
bool problemas = false; 
NewPing sonar(Trig, Echo, MaxDistance);

void setup() {
  //serbastian.attach(9);
  timonteo.attach(11);

  Serial.begin(9600);
  if (tcs.begin()) {

    Serial.println("Inicializando");
    delay(2000);
  } else {
    Serial.println("Error");
    Serial.println("Debe de revisar las conexiones e iniciar nuevamente");
    while (1) delay(500);
  }
}

void loop() {

  uint16_t R, G, B, C;
  tcs.getRawData(&R, &G, &B, &C);

  //angGiro = 0;  //si no detecta color (probablemente blanco) que se mantenga en 0

  /*if (R > 100 && G < 70 && B < 70) {
    angGiro = 180;
  }
  if (G > 50 && R < 80 && B < 80) {
    angGiro = 90;
  }*/

  if (R < 100 && G < 100 && B > 50) {
    confA++;
    confN = 0;
    confB = 0;
  }  //detectar el azul de la pista

  if (R > 100 && G < 150 && B < 100) {

    confN++;
    confA = 0;
    confB = 0;
  }  //detectar el naranaja de la pista

  if (R > 150 && G > 150 && B > 150) {
    confN = 0;
    confA = 0;
    confB++;
  }  //parael blanco
  if (confB > 2)
  {
    color = 0;
    confB = 3;
  }
  if (confN > 2) {
    if (leSabe == false) {
      sentido = 1;  //si no sabemos la dirección y vemos el color naranja, cambiar la dirección
      leSabe = true;
      Serial.println("SENTIDO HORARIO");
    }
    color = 1;
    confN = 3;
  }  //CONFIRMAR si es naranja
  if (confA > 2) {
    if (leSabe == false) {
      leSabe = true;
      Serial.println("SENTIDO ANTIHORARIO");
    }
    color = 2;
    confA = 3;
  }  //CONFIRMAR si es azul

  if (color == 1) //si es naranja
  {
    if (sentido = -1) //y estamos en antihorario
    {
      angGiro = 70;
    }else  //y estamos en horario
    {
      angGiro = 90;
    }
  }else if (color == 2)  //si es azul
  {
    if (sentido = -1) //y estamos en antihorario
    {
      angGiro = 120;
    }else  //y estamos en horario
    {
      angGiro = 90;
    }
  }else //BLANCO
  {
    angGiro = 90;
  }

  if (sonar.ping_cm() < 30) //cuando la distancia sea menor a 10cm
  {
    timonteo.write(90+(sentido * 25));
    problemas = true;
  }
  else
  {
    timonteo.write(angGiro);
  }


  /*if (angCam < 180 && !goBack)
  {
    angCam+= 2;
  }
  if (angCam > 180 && !(angCam < 0))
  {
    goBack = true;
    angCam-= 2;
    if (angCam > 0)
    {
      goBack = false;
    }
  }*/
  Serial.print(sonar.ping_cm());  // obtener el valor en cm (0 = fuera de rango)
  Serial.println("cm");
  //Serial.println(" R = " + String(R) + " G = " + String(G) + " B = " + String(B));
  Serial.println(color);
  Serial.println(curva);
  Serial.println(timonteo.read());
  delay(50);
}