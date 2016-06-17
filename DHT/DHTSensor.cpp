#include "DHTSensor.h"

/**
* DHTSensor
* Default constructor, init class value and set com PIN to 3 
*/
DHTSensor::DHTSensor()
{
	pin = 3;
}

/**
* DHTSensor
* Overrided constructor, init class value and set com PIN with param
* @param int _pin  com pin value
*/
DHTSensor::DHTSensor(int _pin)
{
	pin = _pin;
}

/**
* getTemperature
* Get the current internal temperature
* @return STemperature temperature
*/
STemperature DHTSensor::getTemperature()
{
	return temperature;
}

/**
* getHumidity
* Get the current internal humidity
* @return SHumidity humidity
*/
SHumidity DHTSensor::getHumidity()
{
	return humidity;
}

/**
* read
* Get the current humidity and temperature value form the sensor
* @return bool if success true else false
*/
bool DHTSensor::read()
{
	/* data[] -> buffer contenant les données du cpateur
	* counter -> compteur permettant de savoir quel bit est reçu (bitwise)
	* index -> compteur permettant de savoir quel octet est reçu (bitwise)
	* timeout -> compteur pour le timeout
	*/
	byte data[5] = { 0 }, counter = 7, index = 0;
	unsigned int timeout;
 
	/* Conversion du numéro de broche Arduino en ports/masque binaire "bas niveau" */
	/* Utiliser les registres du microcontrôleur est bien plus rapide que digitalWrite() */
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *ddr = portModeRegister(port); // Registre MODE (INPUT / OUTPUT)
	volatile uint8_t *out = portOutputRegister(port); // Registre OUT (écriture)
	volatile uint8_t *in = portInputRegister(port); // Registre IN (lecture)
 
	/* Réveil du capteur */
	*ddr |= bit; // OUTPUT
	*out &= ~bit; // LOW
	delay(18); // Temps d'attente à LOW causant le réveil du capteur
	*out |= bit; // HIGH
	delayMicroseconds(40);
	*ddr &= ~bit; // INPUT
 
	/* Attente de la réponse du capteur */
	timeout = 0;
	while(!(*in & bit)) /* Attente d'un état LOW */
		if (++timeout == 10000)
			return false;
	timeout = 0;
	while(*in & bit) /* Attente d'un état HIGH */
		if (++timeout == 10000)
			return false;
 
	/* Lecture des données du capteur (40 bits) */
	for (byte i = 0; i < 40; ++i) 
	{
		/* Attente d'un état LOW */
		timeout = 0;
		while(!(*in & bit))
			if (++timeout == 10000)
				return false;
 
		/* Mise en mémoire du temps courant */
		unsigned long t = micros();
 
		/* Attente d'un état HIGH */
		timeout = 0;
		while(*in & bit)
		  if (++timeout == 10000)
			return false;
	 
		/* Si le delta Temps est supérieur à 40µS c'est un "1", sinon c'est un "0" */
		if ((micros() - t) > 40)
			data[index] |= (1 << counter); // "1"
		// Le tableau data[] est initialisé à "0" par défaut??
	 
		/* Si le compteur de bits atteint zéro */
		if (counter-- == 0) 
		{
			counter = 7; /* On passe à l'octet suivant */
			++index;
		}
	}
 
	/* Format des données :
	* [0] = humidité en %
	* [1] = zéro
	* [2] = température en degrés Celsius
	* [3] = zéro
	* [4] = checksum (humidité + température)
	*/
	humidity.humidity = (int)data[0]; 
	temperature.temperature = (int)data[2]; 
 
	/* Vérifie la checksum */
	if (data[4] != (data[0] + data[2]))
		return false; /* Erreur de checksum */
	else
		return true; /* Pas d'erreur */
}
