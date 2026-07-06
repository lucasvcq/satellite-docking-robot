//*******************************************************************************//
// Association des entrées du L298N, aux sorties utilisées sur notre Arduino Uno //
//*******************************************************************************//
#define borneENA        10      // On associe la borne "ENA" du L298N à la pin D10 de l'arduino
#define borneIN1        9       // On associe la borne "IN1" du L298N à la pin D9 de l'arduino
#define borneIN2        8       // On associe la borne "IN2" du L298N à la pin D8 de l'arduino
#define borneIN3        7       // On associe la borne "IN3" du L298N à la pin D7 de l'arduino
#define borneIN4        6       // On associe la borne "IN4" du L298N à la pin D6 de l'arduino
#define borneENB        5       // On associe la borne "ENB" du L298N à la pin D5 de l'arduino
#define borneENC        4
#define borneIN5        3
#define borneIN6        2
int solenoide = 32;

//*******//
// SETUP //
//*******//
void setup() {
  
  // Configuration de toutes les pins de l'Arduino en "sortie" (car elles attaquent les entrées du module L298N)
  pinMode(borneENA, OUTPUT);
  pinMode(borneIN1, OUTPUT);
  pinMode(borneIN2, OUTPUT);
  pinMode(borneIN3, OUTPUT);
  pinMode(borneIN4, OUTPUT);
  pinMode(borneENB, OUTPUT);
  pinMode(solenoide, OUTPUT); 
}

//**************************//
// Boucle principale : LOOP //
//**************************//
void loop() {

  // Configuration du L298N en "marche avant", pour le moteur connecté au pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN1, HIGH);                 // L'entrée IN1 doit être au niveau haut
  digitalWrite(borneIN2, LOW);                  // L'entrée IN2 doit être au niveau bas
  digitalWrite(borneIN3, HIGH);
  digitalWrite(borneIN4, LOW);

  // Et on lance le moteur (branché sur le pont A du L298N)
  lancerRotationMoteurPontA_B();
  
  
  digitalWrite(solenoide, HIGH);   // Active le solenoide
  delay(200);               
  digitalWrite(solenoide, LOW);    // Relache
  delay(1000);


  digitalWrite(borneIN5, HIGH);
  digitalWrite(borneIN6, LOW);

  lancerRotationMoteurPontC();
  while(1);
}




//************************************************************************************//
// Fonction : lancerRotationMoteurPontA()                                             //
// But :      Active l'alimentation du moteur branché sur le pont A                   //
//            pendant 2 secondes, puis le met à l'arrêt (au moins 1 seconde)          //
//************************************************************************************//
void lancerRotationMoteurPontA_B() {
  digitalWrite(borneENA, HIGH);       // Active l'alimentation du moteur 1
  digitalWrite(borneENB, HIGH); 
  delay(5000);                        // et attend 2 secondes
  
  digitalWrite(borneENA, LOW);        // Désactive l'alimentation du moteur 1
  digitalWrite(borneENB, LOW);
  delay(1000);                        // et attend 1 seconde
}


void lancerRotationMoteurPontC() {
  digitalWrite(borneENC, HIGH);       // Active l'alimentation du moteur 1 
  delay(12000);                        // et attend 2 secondes
  
  digitalWrite(borneENC, LOW);        // Désactive l'alimentation du moteur 1
  delay(1000);                        // et attend 1 seconde
}