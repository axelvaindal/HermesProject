#include "DHTSensor.h"

/**
* DHTSensor
* Default constructor, init class value and set com PIN to 3 
*/
DHTSensor::DHTSensor()
{
	pin = 3;
	temperature = 0;
	humidity = 0;
}

/**
* DHTSensor
* Overrided constructor, init class value and set com PIN with param
* @param int _pin  com pin value
*/
DHTSensor::DHTSensor(int _pin)
{
	pin = _pin;
	temperature = 0;
	humidity = 0;
}

/**
* getTemperature
* Get the current internal temperature
* @return int8_t temperature
*/
int8_t DHTSensor::getTemperature()
{
	return temperature;
}

/**
* getHumidity
* Get the current internal humidity
* @return int8_t humidity
*/
int8_t DHTSensor::getHumidity()
{
	return humidity;
}

/**
* readDHT
* Get the current humidity and temperature value form the sensor
* @return bool if success true else false
*/
bool DHTSensor::readDHT()
{
	/* data[] -> buffer contenant les donn�es du cpateur
	* counter -> compteur permettant de savoir quel bit est re�u (bitwise)
	* index -> compteur permettant de savoir quel octet est re�u (bitwise)
	* timeout -> compteur pour le timeout
	*/
	byte data[5] = { 0 }, counter = 7, index = 0;
	unsigned int timeout;
 
	/* Conversion du num�ro de broche Arduino en ports/masque binaire "bas niveau" */
	/* Utiliser les registres du microcontr�leur est bien plus rapide que digitalWrite() */
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *ddr = portModeRegister(port); // Registre MODE (INPUT / OUTPUT)
	volatile uint8_t *out = portOutputRegister(port); // Registre OUT (�criture)
	volatile uint8_t *in = portInputRegister(port); // Registre IN (lecture)
 
	/* R�veil du capteur */
	*ddr |= bit; // OUTPUT
	*out &= ~bit; // LOW
	delay(18); // Temps d'attente � LOW causant le r�veil du capteur
	*out |= bit; // HIGH
	delayMicroseconds(40);
	*ddr &= ~bit; // INPUT
 
	/* Attente de la r�ponse du capteur */
	timeout = 0;
	while(!(*in & bit)) /* Attente d'un �tat LOW */
		if (++timeout == 10000)
			return false;
	timeout = 0;
	while(*in & bit) /* Attente d'un �tat HIGH */
		if (++timeout == 10000)
			return false;
 
	/* Lecture des donn�es du capteur (40 bits) */
	for (byte i = 0; i < 40; ++i) 
	{
		/* Attente d'un �tat LOW */
		timeout = 0;
		while(!(*in & bit))
			if (++timeout == 10000)
				return false;
 
		/* Mise en m�moire du temps courant */
		unsigned long t = micros();
 
		/* Attente d'un �tat HIGH */
		timeout = 0;
		while(*in & bit)
		  if (++timeout == 10000)
			return false;
	 
		/* Si le delta Temps est sup�rieur � 40�S c'est un "1", sinon c'est un "0" */
		if ((micros() - t) > 40)
			data[index] |= (1 << counter); // "1"
		// Le tableau data[] est initialis� � "0" par d�faut??
	 
		/* Si le compteur de bits atteint z�ro */
		if (counter-- == 0) 
		{
			counter = 7; /* On passe � l'octet suivant */
			++index;
		}
	}
 
	/* Format des donn�es :
	* [0] = humidit� en %
	* [1] = z�ro
	* [2] = temp�rature en degr�s Celsius
	* [3] = z�ro
	* [4] = checksum (humidit� + temp�rature)
	*/
	humidity = (int)data[0]; 
	temperature = (int)data[2]; 
 
	/* V�rifie la checksum */
	if (data[4] != (data[0] + data[2]))
		return false; /* Erreur de checksum */
	else
		return true; /* Pas d'erreur */
}
