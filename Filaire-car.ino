// include
#include <SoftwareSerial.h>
String message;

/**
* Déclaration/Initialisation de cariable de port.
*/

// Pin principaux.
int pinM1 = 4;
int pinM2 = 12;

// Pin Vitesse.
int pinVM1 = 3;
int pinVM2 = 11;

// Broche
int portPot = 0;
int portPotTurn = 1;

/**
* Déclaration de variable de valeur
*/
int val = 0;
int valTurn = 0;
int valMoteur = 0;
int valMoteurTurn = 0;

void setup()
{
  // Démarrer la liaison Bluetooth
  Serial.begin(9600);
  // Démarrer la liaison Série
  bluetooth.begin(9600);

  
  // pinMode des moteurs.
  pinMode(pinM1, OUTPUT);
  pinMode(pinM2, OUTPUT);

  pinMode(pinVM1, OUTPUT);
  pinMode(pinVM2, OUTPUT);
  
}

void loop()
{  
 
  val = analogRead(portPot); // Valeur du potentiomètre
  valTurn = analogRead(portPotTurn); // Valeur du potentiomètre tournant
  
  valMoteur = map(val,0,1023,0,255);

  if(val > 511.5) {
     valMoteur = map(val,1023/2,1023,0,255);
     digitalWrite(pinM1, LOW);
     digitalWrite(pinM2, LOW);

     if(valTurn > 1023/2) {
         left(valMoteur);
     } else if(valTurn < 1023/2 and valTurn > 409) {
         defaut(valMoteur);
     } else if(valTurn < 409) {
         rigth(valMoteur);
//      }
      
 } else {
     valMoteur = map(val,0,1023/2,255,0);
     digitalWrite(pinM1, HIGH);
     digitalWrite(pinM2, HIGH);
     
     if(valTurn > 1023/2) {
         left(valMoteur);
     } else if(valTurn < 1023/2 and valTurn > 409) {
         defaut(valMoteur);
     } else if(valTurn < 409) {
         rigth(valMoteur);
     }
      
 }
  
  delay(500);
  
}

// defaut moteur
void up(int etat) { 
    digitalWrite(pinM1, LOW);
    digitalWrite(pinM2, LOW); 
    analogWrite(pinVM1, etat);
    analogWrite(pinVM2, etat); 
}

void back(int etat) {
    digitalWrite(pinM1, HIGH);
    digitalWrite(pinM2, HIGH);
    analogWrite(pinVM1, etat);
    analogWrite(pinVM2, etat); 
}

void rigth(int etat) {
    analogWrite(pinVM1, 0);
    analogWrite(pinVM2, etat); 
}

void left(int etat) {
    analogWrite(pinVM1, etat);
    analogWrite(pinVM2, 0); 
}
