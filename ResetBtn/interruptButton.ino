const byte ledPin =8;
const byte interruptPin =3;
volatile byte state = LOW;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), ButtonPress, RISING);
}

void loop() 
{
  digitalWrite(ledPin, state);
}

void ButtonPress()
{
  state =!state;
}
