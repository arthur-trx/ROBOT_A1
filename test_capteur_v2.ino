
#include <Wire.h>
#include <LiquidCrystal.h>
#define adresse_out 0x20
#define adresse_in 0x24 
#define capteur_G A1
#define capteur_M A2
#define capteur_D A0
#define LED1 13
#define LED2 12
#define LED3 11


LiquidCrystal lcd(7, 8, 9, 13, 12, 11, 10); // déclare une variable LiquidCrystal appelée lcd

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // baud
  Wire.begin();
  lcd.begin(16, 2);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode (capteur_G, INPUT);
  pinMode (capteur_M, INPUT);
  pinMode (capteur_D, INPUT);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
  pinMode (LED3, OUTPUT);
  
}
int getCapteurG (){
  
}

void motor(byte out){
  Wire.beginTransmission(adresse_out);
  Wire.write(out);       
  Wire.endTransmission(); 
}
void vitesse_G(int vitesse){
  analogWrite (6, vitesse);
}

void vitesse_D(int vitesse){
  analogWrite (7, vitesse);
}



int aller_tout_droit (int vitesse_max){
  motor(B00000101);
  vitesse_G(vitesse_max); vitesse_D (vitesse_max);
  

  return 0;
  
}

void loop() {
  byte av = B00000101;
  byte re = B00001010;
  byte dra = B00000001;
  byte gaa = B00000100; 
  byte drr = B00000010;
  byte gar = B00001000;

 float cap_G = analogRead (capteur_G); Serial.print ("1  :  "); Serial.print(cap_G); Serial.print("     ");
 float cap_M = analogRead (capteur_M); Serial.print ("2  :  "); Serial.print(cap_M); Serial.print("     ");
 float cap_D = analogRead (capteur_D); Serial.print ("3  :  "); Serial.print(cap_D); Serial.println();
 
  if (cap_G > 600) digitalWrite(LED1, HIGH);
  else digitalWrite(LED1, LOW);
  if (cap_M > 600) digitalWrite(LED2, HIGH);
  else digitalWrite(LED2, LOW);
  if (cap_D > 600) digitalWrite(LED3, HIGH);
  else digitalWrite(LED3, LOW);
  

  
}
/*
 télécommande
 byte : i1 i2 i3 i4 MG MD R A
 */
