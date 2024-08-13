
const int trigPin = 12;
const int echoPin = 11;
const int relay1 = 4;
const int relay2 = 2;
const int pinocho = 8;
int pingTravelTime;

int waitCorner = 0;

int sentido = -1;      //la dirección (1 horario, -1 antihorario)

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pinocho, OUTPUT);
  Serial.begin(9600);
  Serial.println("Started!");
}

void loop() {
  /*if (!(waitCorner == 0))
  {
    waitCorner = waitCorner-1;
  }*/
  digitalWrite(pinocho, LOW);
  digitalWrite(relay1, LOW);  // Ambos relés apagados
  digitalWrite(relay2, LOW);
  if (pingTravelTime < 1000) //cuando la distancia sea menor a 10cm
  {
    digitalWrite(relay1, HIGH);  // Ambos relés apagados
    digitalWrite(relay2, LOW);
    digitalWrite(pinocho, LOW);
  }
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  pingTravelTime= pulseIn(echoPin, HIGH);

  delay(25);
  digitalWrite(trigPin, LOW);
  Serial.println(pingTravelTime);
}