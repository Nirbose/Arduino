// Broche
int bp = 3;

void setup() {
  Serial.begin(9600);

  pinMode(bp, INPUT);
}

void loop() {
  int val = digitalRead(bp);
  
  if(val) {
    Serial.println("Le bouton est activée !");
  }
}
