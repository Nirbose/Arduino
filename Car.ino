// include
#include <SoftwareSerial.h>
String message;

/**
* Déclaration/Initialisation de cariable de port.
*/

SoftwareSerial bluetooth(7, 8);

// Pin principaux.
int pinM1 = 4;
int pinM2 = 12;

// Pin Vitesse.
int pinVM1 = 3;
int pinVM2 = 11;

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

  if (bluetooth.available()) {
    message = bluetooth.read();
    
    if(message.toInt() == 49) {
        up(255);
        
    }else if(message.toInt() == 50) {
        rigth(255);
        
    }else if(message.toInt() == 51) {
        left(255);
        
    } else if(message.toInt() == 52) {
        back(255);
        
    }else if(message.toInt() == 53){
        up(0);
        back(0);
        
    }
  }

  delay(100);
  
}

// defaut moteur
void up(int etat) {
    digitalWrite(pinM1, LOW);
    analogWrite(pinVM1, etat);
    digitalWrite(pinM2, LOW);
    analogWrite(pinVM2, etat); 
}

void back(int etat) {
    digitalWrite(pinM1, HIGH);
    analogWrite(pinVM1, etat);
    digitalWrite(pinM2, HIGH);
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
