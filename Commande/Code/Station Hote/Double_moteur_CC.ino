/*
   ______               _                  _///  _           _                   _
  /   _  \             (_)                |  __\| |         | |                 (_)
  |  [_|  |__  ___  ___ _  ___  _ __      | |__ | | ___  ___| |_ _ __ ___  _ __  _  ___  _   _  ___
  |   ___/ _ \| __|| __| |/ _ \| '_ \_____|  __|| |/ _ \/  _|  _| '__/   \| '_ \| |/   \| | | |/ _ \
  |  |  | ( ) |__ ||__ | | ( ) | | | |____| |__ | |  __/| (_| |_| | | (_) | | | | | (_) | |_| |  __/
  \__|   \__,_|___||___|_|\___/|_| [_|    \____/|_|\___|\____\__\_|  \___/|_| |_|_|\__  |\__,_|\___|
                                                                                      | |
                                                                                      \_|
  Fichier:      MarcheArretMoteurL298N
  Description:  Exemple de code Arduino, permettant de faire tourner un moteur à courant continu (marche avnat/marche arrière), via un module L298N branché sur un Arduino Uno
  Auteur:       Jérôme, Passion-Électronique (https://passionelectronique.fr/)
  Création :    05.05.2021
*/

//*******************************************************************************//
// Association des entrées du L298N, aux sorties utilisées sur notre Arduino Uno //
//*******************************************************************************//
#define borneENA        10      // On associe la borne "ENA" du L298N à la pin D10 de l'arduino
#define borneIN1        9       // On associe la borne "IN1" du L298N à la pin D9 de l'arduino
#define borneIN2        8       // On associe la borne "IN2" du L298N à la pin D8 de l'arduino
#define borneIN3        7       // On associe la borne "IN3" du L298N à la pin D7 de l'arduino
#define borneIN4        6       // On associe la borne "IN4" du L298N à la pin D6 de l'arduino
#define borneENB        5       // On associe la borne "ENB" du L298N à la pin D5 de l'arduino


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
}

//**************************//
// Boucle principale : LOOP //
//**************************//
void loop() {

  // Configuration du L298N en "marche avant", pour le moteur connecté au pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN1, HIGH);                 // L'entrée IN1 doit être au niveau haut
  digitalWrite(borneIN2, LOW);                  // L'entrée IN2 doit être au niveau bas

  // Et on lance le moteur (branché sur le pont A du L298N)
  lancerRotationMoteurPontA();

  // Puis on configure le L298N en "marche arrière", pour le moteur câblé sur le pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN1, LOW);                  // L'entrée IN1 doit être au niveau bas
  digitalWrite(borneIN2, HIGH);                 // L'entrée IN2 doit être au niveau haut

// Configuration du L298N en "marche avant", pour le moteur connecté au pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN3, HIGH);                 // L'entrée IN1 doit être au niveau haut
  digitalWrite(borneIN4, LOW);                  // L'entrée IN2 doit être au niveau bas

  // Et on lance le moteur (branché sur le pont A du L298N)
  lancerRotationMoteurPontA();

  // Puis on configure le L298N en "marche arrière", pour le moteur câblé sur le pont A. Selon sa table de vérité, il faut que :
  digitalWrite(borneIN3, LOW);                  // L'entrée IN1 doit être au niveau bas
  digitalWrite(borneIN4, HIGH);                 // L'entrée IN2 doit être au niveau haut

  // Et on relance le moteur (branché sur le pont A du L298N)
  lancerRotationMoteurPontA();
  
  // Puis... on boucle à l'infini !
}


//************************************************************************************//
// Fonction : lancerRotationMoteurPontA()                                             //
// But :      Active l'alimentation du moteur branché sur le pont A                   //
//            pendant 2 secondes, puis le met à l'arrêt (au moins 1 seconde)          //
//************************************************************************************//
void lancerRotationMoteurPontA() {
  digitalWrite(borneENA, HIGH);       // Active l'alimentation du moteur 1
  delay(2000);                        // et attend 2 secondes
  
  digitalWrite(borneENA, LOW);        // Désactive l'alimentation du moteur 1
  delay(1000);                        // et attend 1 seconde

  digitalWrite(borneENB, HIGH);       // Active l'alimentation du moteur 1
  delay(2000);                        // et attend 2 secondes
  
  digitalWrite(borneENB, LOW);        // Désactive l'alimentation du moteur 1
  delay(1000);                        // et attend 1 seconde
}