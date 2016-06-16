const byte ledPin =8;
const byte interruptPin =3;
volatile byte state = LOW; 

void setup() 
{
  //initilisation des pins
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  /**
   * initialisation de l'interruption.
   * l'interruption se déclenche lorsque interuptPin passe de l'état bas à l'état haut
   */
  
  attachInterrupt(digitalPinToInterrupt(interruptPin), ButtonPress, RISING);
}

void loop() 
{
  //allume la LED
  digitalWrite(ledPin, state);
}

void ButtonPress()
{
  //changement d'etat de la variable booléen
  state =!state;
}
