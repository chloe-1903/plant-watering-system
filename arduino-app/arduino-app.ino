    //****************************************************
    // Mesure analogique et digitale de l'humidité du sol
    // Avec le module Humidité Sol
    //  TipTopboards.com
    //  23 12 2013  demo_hsol
    //****************************************************
    // Brancher +V -> 5V et GND
    // Sortie analogique du capteur -> A0 Arduino
    // Sortie digitale du capteur -> pin 3 Arduino (avec seuil)

    //On rajoute une LEd témoin sur pin 4

    int PinAnalogiqueHumidite=0;       //Broche Analogique de mesure d'humidité
    int pinSwitch=12;

    int hsol;  //Humidite su sol, mesure analogique
    int seuil = 300;

    void setup(){ // Initialisation
        Serial.begin(9600);  //Connection série à 9600 baud
        pinMode(PinAnalogiqueHumidite, INPUT);       //pin A0 en entrée analogique
        pinMode(pinSwitch,OUTPUT); //signale a l arduino que la connexion 13 doit pouvoir envoyer du courant
        pinMode(LED_BUILTIN, OUTPUT);   //LED témoin
    }

    void loop() { //boucle principale
        //TODO: let the humidity captor sleep to avoid using it too much (it will damage it)
        hsol = analogRead(PinAnalogiqueHumidite); // Lit la tension analogique
        Serial.println(hsol); // afficher la mesure
        Serial.print("  ");
        if (hsol<=seuil) {
            //If not dry, ne need to do anything
            digitalWrite(LED_BUILTIN, LOW);   // LED OFF
        }
        else {
            //If it is dry, we start the pump to water
            digitalWrite(pinSwitch,HIGH); // demande  l'ardui d'evoyer du courant dans la broche 13. Met la broche 13 à 5V
            delay (1000); // attendre 1 seconde
            digitalWrite(pinSwitch,LOW); // demande  l'ardui de mettre la connexion 13
            delay (15000);// attendre 1 seconde
            digitalWrite(LED_BUILTIN, HIGH);//LED ON
        }
        delay(1000); //delai entre 2 mesures: 20ms
    }
