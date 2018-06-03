/*
* Senzor de parcare cu senzor cu ultrasunete (HC-SR04) si Arduino Mega
*
*Savu Raoul
*/
#include <LiquidCrystal.h> 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creaza obiectul LCD cu parametrii sai(rs, enable, d4, d5, d6, d7)
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm;
const int sw1;
const int sw2;

void setup() {
lcd.begin(16,2); // Initializeaza interfata cu ecranul LCD, si specifica dimensiunile (latime si inaltime) ale displayului
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

pinMode(14, OUTPUT); //LED verde
pinMode(15, OUTPUT); //LED rosu
pinMode(16, OUTPUT); //buzzer 
}
void loop() {
//initiali7zare valoare switch-uri

//citire distanta
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

//calculare distanta pe baza duratei de primire a ecoului
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;

lcd.setCursor(0,0); // Seteaza locatia de incepere a afisarii pe LCD
lcd.print("Distanta: "); 
lcd.print(distanceCm); 
lcd.print(" cm  ");
delay(200);

if(distanceCm <= 60 && distanceCm > 45)
{
  lcd.setCursor(0,1);
  lcd.print("Atentie!!!");
  digitalWrite(14, HIGH);
  digitalWrite(16, HIGH);
  delay(400);
  digitalWrite(14, LOW);
  digitalWrite(16, LOW);
  delay(400);
}
else
if (distanceCm <= 45 && distanceCm > 31)
  {
  lcd.setCursor(0,1);
  lcd.print("ATENTIE!!!");
  digitalWrite(14, HIGH);
  digitalWrite(16, HIGH);
  delay(300);
  digitalWrite(14, LOW);
  digitalWrite(16, LOW);
  delay(300);
}
else
if (distanceCm <= 30 && distanceCm > 16)
  {
  lcd.setCursor(0,1);
  lcd.print("PERICOL!!!");
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  delay(200);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  delay(200);
}
else
if (distanceCm <= 15 && distanceCm > 0)
  {
  lcd.setCursor(0,1);
  lcd.print("CALCA FRANA!!!");
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  delay(100);
  digitalWrite(15, LOW);
  digitalWrite(16, LOW);
  delay(100);
}


}
