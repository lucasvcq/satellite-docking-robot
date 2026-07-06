int solenoide = 11;

void setup() {                
  pinMode(solenoide, OUTPUT);     
}
void loop() {
  digitalWrite(solenoide, HIGH);   // Active le solenoide
  delay(50);               
  digitalWrite(solenoide, LOW);    // Relache
  delay(1000);
}