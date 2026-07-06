void setup() {
  Serial.begin(9600); // Initialise la communication série à 9600 bauds
}

void loop() {
  Serial.println("Bonjour Arduino!"); // Envoie "Bonjour Arduino!" via UART
  delay(500); // Attente d'une seconde
}
