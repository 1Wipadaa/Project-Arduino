
#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int ledMovimento = 11;
const int ledSemMovimento = 12;
Servo meuServo;

long duracao;
int distancia;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledMovimento, OUTPUT);
  pinMode(ledSemMovimento, OUTPUT);
  meuServo.attach(6);
  meuServo.write(90);
  digitalWrite(ledSemMovimento, HIGH);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);
  distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distancia);

  if (distancia <= 20) { // เปลี่ยนจาก 100 เป็น 50 ซม.
    meuServo.write(180); // หมุนไปที่ 45 องศา
    digitalWrite(ledMovimento, HIGH);
    digitalWrite(ledSemMovimento, LOW);
    
  } else {
    meuServo.write(90); // กลับไปที่ 90 องศา
    digitalWrite(ledMovimento, LOW);
    digitalWrite(ledSemMovimento, HIGH);
  }

  delay(1800);
}