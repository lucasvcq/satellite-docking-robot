#include <RH_ASK.h>

#ifdef RH_HAVE_HARDWARE_SPI
#include <SPI.h> // Nécessaire pour la compilation
#endif

RH_ASK driver(2000, 13, 12, 14); // Fréquence, RX, TX, PTT – TX et PTT ne sont pas utilisés ici


//*******************************************************************************//
// Association des entrées et des sorties utilisées sur notre Arduino Mega //
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
int solenoide_treuil = 32;
int solenoide_docking = 33;




//*************************************************//
//      Verrouillage : ENA, ENB, IN1/2/3/4         //
//      Treuil : ENC, IN5/6                        //
//                                                 //  
//                                                 //
//*************************************************//


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
  pinMode(solenoide_treuil, OUTPUT);
  pinMode(solenoide_docking, OUTPUT);  
  pinMode(borneIN5, OUTPUT);
  pinMode(borneIN6, OUTPUT);
}



//**************************//
// Boucle principale : LOOP //
//**************************//
void loop() {
  digitalWrite(solenoide_docking, HIGH);   // Active le solenoide docking
  delay(2000);

//////////////////////////ON ACTIVE LE BOUTON pour éjecter/////////////////////////
  digitalWrite(solenoide_docking, LOW);   // Desactive le solenoide docking
  delay(1000);
  digitalWrite(solenoide_treuil, LOW);   // Active le solenoide treuil
  delay(1500);   



  // Configuration des moteurs verrouillages
  digitalWrite(borneIN1, HIGH);                
  digitalWrite(borneIN2, LOW);                  
  digitalWrite(borneIN3, HIGH);
  digitalWrite(borneIN4, LOW);

  // Et on lance le moteur 
  lancerRotationMoteurPontA_B();


//////////////////////////ON ACTIVE LE BOUTON pour faire revenir le robot/////////////////////////
  // Configuration du moteur treuil
  digitalWrite(borneIN5, HIGH);
  digitalWrite(borneIN6, LOW);

  digitalWrite(solenoide_treuil, HIGH);   // Active le solenoide treuil
  delay(1500);

  lancerRotationMoteurPontC();

 


  digitalWrite(solenoide_docking, HIGH);   // Desactive le solenoide docking
  delay(1000);


/////RAJOUTER UN BOUTON D'URGENCE///////

  while(1);
}




//************************************************************************************//
// Fonction : lancerRotationMoteurPontA_B()    Moteurs Verrouillage                                         //
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

//************************************************************************************//
// Fonction : lancerRotationMoteurPontC()     Moteur Treuil                                        //
// But :      Active l'alimentation du moteur branché sur le pont C                   //
//            pendant 2 secondes, puis le met à l'arrêt (au moins 1 seconde)          //
//************************************************************************************//

void lancerRotationMoteurPontC() {
  digitalWrite(borneENC, HIGH);       // Active l'alimentation du moteur 1 
  delay(12000);                        // et attend 2 secondes
  
  digitalWrite(borneENC, LOW);        // Désactive l'alimentation du moteur 1
  delay(1000);                        // et attend 1 seconde
}