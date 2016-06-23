#include "BufferManager.h"

/*
* Default constructor
*/
BufferManager::BufferManager()
{
	bufferInit(&bufferGPS, MAXSIZE_GPS, sizeof(SCoordinate));
	bufferInit(&bufferLinearAcceleration, MAXSIZE_LINEARACCELERATION, sizeof(SLinearAcceleration));
	bufferInit(&bufferAngularAcceleration, MAXSIZE_ANGULARACCELERATION, sizeof(SAngularAcceleration));
	bufferInit(&bufferHumidity, MAXSIZE_HUMIDITY, sizeof(SHumidity));
	bufferInit(&bufferTemperature, MAXSIZE_TEMPERATURE, sizeof(STemperature));
	bufferInit(&bufferLight, MAXSIZE_LIGHT, sizeof(SLight));
	bufferInit(&bufferAlert, MAXSIZE_ALERT, sizeof(SAlert));
}

/*
* Destructor
*/
BufferManager::~BufferManager()
{
	bufferFree(&bufferGPS);
	bufferFree(&bufferLinearAcceleration);
	bufferFree(&bufferAngularAcceleration);
	bufferFree(&bufferHumidity);
	bufferFree(&bufferTemperature);
	bufferFree(&bufferLight);
	bufferFree(&bufferAlert);
}



/******************
* Generic methods
*******************/


/*
* BufferManager::bufferInit
* Method to initialize a single buffer
* @param {SCircularBuffer*} cb 	 The buffer to initialize
* @param {uint8_t} capacity 		 The maximum capacity of the buffer (number of items)
* @param {uint8_t} itemSize The size of a single item
* @return {void}
*/
void BufferManager::bufferInit(SCircularBuffer* cb, uint8_t capacity, uint8_t itemSize)
{
	// Memory allocation
	cb->buffer = malloc(capacity * itemSize);
	
	// Check if allocation went well
    if(cb->buffer == NULL)
		return; // handle error
        
	
	// Determination of the end of the buffer according to max capacity and item size
    cb->bufferEnd = (char *)(cb->buffer + capacity * itemSize);
	
	
    cb->capacity = capacity;
    cb->count = 0;
    cb->itemSize = itemSize;
	
	// Head and tail are in the first position at the begining
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
}


/*
* BufferManager::bufferFree
* Method to free a single buffer
* @param {SCircularBuffer*} cb 	 The buffer to free
* @return {void}
*/
void BufferManager::bufferFree(SCircularBuffer* cb)
{
	// free memory
	free(cb->buffer);
	
	// To add? : clearing all fields, even if not necessary, just to be safe
}


/*
* BufferManager::genericPush
* Method to push any data into a specific buffer. 
* If the buffer is full, delete the oldest data and replace it by the new one.
* @param {SCircularBuffer*} cb 	 The buffer to push
* @param {void*} data 			 The data to store
* @return {void}
*/
void BufferManager::genericPush(SCircularBuffer* cb, void* data)
{
	
	// Check if there is empty space in the buffer
	if(cb->count == cb->capacity)
    {
		// In the case there is none, we delete the oldest data and push the new one
		// So we just delete the oldest item (the one in the tail so), and move the tail to the next one
		
		// Move the tail to the next data to read
		cb->tail = (char*)(cb->tail + cb->itemSize);
		
		// If the tail reach the buffer end, go to the first memory slot
		if(cb->tail == cb->bufferEnd)
			cb->tail = cb->buffer;
		
		// Decrement the item counter
		cb->count--;
		
	}
	
	// Copy the item in the head of buffer
    memcpy(cb->head, data, cb->itemSize);
	
	// Move the head pointer to the next empty slot
    cb->head = (char*)(cb->head + cb->itemSize);
	
	// If the head reach the buffer end, go to the first memory slot
    if(cb->head == cb->bufferEnd)
        cb->head = cb->buffer;
	
	// Increment the item counter
    cb->count++;
}

/*
* BufferManager::genericPop
* Generic method to pop data from a specific buffer
* @param {SCircularBuffer*} cb 	 The buffer to pop
* @param {void*} item 			 The item used to store the result
* @return {bool}	Return true if a data has been found, or false if the buffer is empty.
*/
bool BufferManager::genericPop(SCircularBuffer* cb, void* item)
{
	// Check if there is data in the buffer
	if(cb->count == 0)
        return false;
	
	// Copy the buffer content at the tail into the item
    memcpy(item, cb->tail, cb->itemSize);
	
	// Move the tail to the next data to read
    cb->tail = (char*)(cb->tail + cb->itemSize);
	
	// If the tail reach the buffer end, go to the first memory slot
    if(cb->tail == cb->bufferEnd)
        cb->tail = cb->buffer;
	
	// Decrement the item counter
    cb->count--;
	
	return true;
}



/*
* BufferManager::dataAvailable
* Generic method to check if the buffer contains data
* @param {SCircularBuffer*} cb 	 The buffer to check
* @return {bool}	Return true if the buffer contains data, false otherwise.
*/
bool BufferManager::dataAvailable(SCircularBuffer* cb)
{
	if(cb->count > 0)
		return true;
	else
		return false;
}

/*
* BufferManager::dataCount
* Generic method to get the item count from a buffer
* @param {SCircularBuffer*} cb 	 The buffer to count
* @return {bool}	Return the item count
*/
uint8_t BufferManager::dataCount(SCircularBuffer* cb)
{
	return cb->count;
}




/***************
* Push methods
***************/


/*
* BufferManager::pushGPS
* Method to push a SCoordinate data into the GPS buffer
* @param {SCoordinate*} data 	The data to store
* @return {void}
*/
void BufferManager::pushGPS(SCoordinate* data)
{
	genericPush(&bufferGPS, data);
}

/*
* BufferManager::pushLinearAcceleration
* Method to push a SLinearAcceleration data into the Linear acceleration buffer
* @param {SLinearAcceleration*} data 	The data to store
* @return {void}
*/
void BufferManager::pushLinearAcceleration(SLinearAcceleration* data)
{
	genericPush(&bufferLinearAcceleration, data);
}

/*
* BufferManager::pushAngularAcceleration
* Method to push a SAngularAcceleration data into the Angular acceleration buffer
* @param {SAngularAcceleration*} data 	The data to store
* @return {void}
*/
void BufferManager::pushAngularAcceleration(SAngularAcceleration* data)
{
	genericPush(&bufferAngularAcceleration, data);
}

/*
* BufferManager::pushHumidity
* Method to push a SHumidity data into the Humidity buffer
* @param {SHumidity*} data 	The data to store
* @return {void}
*/
void BufferManager::pushHumidity(SHumidity* data)
{
	SAlert alert;
	genericPush(&bufferHumidity, data);
	if(this->alertManager->checkHumidity(&alert, data))
	{
		pushAlert(&alert);
	}
}

/*
* BufferManager::pushTemperature
* Method to push a STemperature data into the Temperature buffer
* @param {STemperature*} data 	The data to store
* @return {void}
*/
void BufferManager::pushTemperature(STemperature* data)
{
	genericPush(&bufferTemperature, data);
}

/*
* BufferManager::pushLight
* Method to push a SLight data into the Light buffer
* @param {SLight*} data 	The data to store
* @return {void}
*/
void BufferManager::pushLight(SLight* data)
{
	SAlert alert;
	genericPush(&bufferLight, data);
	if(this->alertManager->checkLight(&alert, data))
	{
		pushAlert(&alert);
	}
}

/*
* BufferManager::pushAlert
* Method to push a SAlert data into the Alert buffer
* @param {SAlert*} data 	The data to store
* @return {void}
*/
void BufferManager::pushAlert(SAlert* data)
{
	genericPush(&bufferAlert, data);
}



/***************
* Pop methods
***************/

/*
* BufferManager::popGPS
* Method to pop a SCoordinate data from the GPS buffer
* @param {SCoordinate*} data 	The item used to store the result
* @return {bool} Return true if a data has been found, or false if the buffer is empty.
*/
bool BufferManager::popGPS(SCoordinate* result)
{
	return genericPop(&bufferGPS, result);
}

/*
* BufferManager::popLinearAcceleration
* Method to pop a SLinearAcceleration data from the Linear acceleration buffer
* @param {SLinearAcceleration*} data 	The item used to store the result
* @return {bool} Return true if a data has been found, or false if the buffer is empty.
*/
bool BufferManager::popLinearAcceleration(SLinearAcceleration* result)
{
	return genericPop(&bufferLinearAcceleration, result);
}

/*
* BufferManager::popAngularAcceleration
* Method to pop a SAngularAcceleration data from the Angular acceleration buffer
* @param {SAngularAcceleration*} data 	The item used to store the result
* @return {bool} Return true if a data has been found, or false if the buffer is empty.
*/
bool BufferManager::popAngularAcceleration(SAngularAcceleration* result)
{
	return genericPop(&bufferAngularAcceleration, result);
}

/*
* BufferManager::popHumidity
* Method to pop a SHumidity data from the Humidity buffer
* @param {SHumidity*} data 	The item used to store the result
* @return {bool} Return true if a data has been found, or false if the buffer is empty.
*/
bool BufferManager::popHumidity(SHumidity* result)
{
	return genericPop(&bufferHumidity, result);
}

/*
* BufferManager::popTemperature
* Method to pop a STemperature data from the Temperature buffer
* @param {STemperature*} data 	The item used to store the result
* @return {bool} Return true if a data has been found, or false if the buffer is empty.
*/
bool BufferManager::popTemperature(STemperature* result)
{
	return genericPop(&bufferTemperature, result);
}

/*
* BufferManager::popLight
* Method to pop a SLight data from the Light buffer
* @param {SLight*} data 	The item used to store the result
* @return {bool} Return true if a data has been found, or false if the buffer is empty.
*/
bool BufferManager::popLight(SLight* result)
{
	return genericPop(&bufferLight, result);
}

/*
* BufferManager::popAlert
* Method to pop a SAlert data from the Alert buffer
* @param {SAlert*} data 	The item used to store the result
* @return {bool} Return true if a data has been found, or false if the buffer is empty.
*/
bool BufferManager::popAlert(SAlert* result)
{
	return genericPop(&bufferAlert, result);
}


/******************
* Checking methods
******************/

/*
* BufferManager::dataAvailableGPS
* Method to check if the buffer contains data
* @return {bool} Return true if the buffer contains data, false otherwise.
*/
bool BufferManager::dataAvailableGPS()
{
	return dataAvailable(&bufferGPS);
}

/*
* BufferManager::dataAvailableLinearAcceleration
* Method to check if the buffer contains data
* @return {bool} Return true if the buffer contains data, false otherwise.
*/
bool BufferManager::dataAvailableLinearAcceleration()
{
	return dataAvailable(&bufferLinearAcceleration);
}

/*
* BufferManager::dataAvailableAngularAcceleration
* Method to check if the buffer contains data
* @return {bool} Return true if the buffer contains data, false otherwise.
*/
bool BufferManager::dataAvailableAngularAcceleration()
{
	return dataAvailable(&bufferAngularAcceleration);
}

/*
* BufferManager::dataAvailableHumidity
* Method to check if the buffer contains data
* @return {bool} Return true if the buffer contains data, false otherwise.
*/
bool BufferManager::dataAvailableHumidity()
{
	return dataAvailable(&bufferHumidity);
}

/*
* BufferManager::dataAvailableTemperature
* Method to check if the buffer contains data
* @return {bool} Return true if the buffer contains data, false otherwise.
*/
bool BufferManager::dataAvailableTemperature()
{
	return dataAvailable(&bufferTemperature);
}

/*
* BufferManager::dataAvailableLight
* Method to check if the buffer contains data
* @return {bool} Return true if the buffer contains data, false otherwise.
*/
bool BufferManager::dataAvailableLight()
{
	return dataAvailable(&bufferLight);
}

/*
* BufferManager::dataAvailableAlert
* Method to check if the buffer contains data
* @return {bool} Return true if the buffer contains data, false otherwise.
*/
bool BufferManager::dataAvailableAlert()
{
	return dataAvailable(&bufferAlert);
}


/*
* BufferManager::dataCountGPS
* Method to get the current count of data into the buffer
* @return {uint8_t} Return the item count
*/
uint8_t BufferManager::dataCountGPS()
{
	return dataCount(&bufferGPS);
}

/*
* BufferManager::dataCountLinearAcceleration
* Method to get the current count of data into the buffer
* @return {uint8_t} Return the item count
*/
uint8_t BufferManager::dataCountLinearAcceleration()
{
	return dataCount(&bufferLinearAcceleration);
}

/*
* BufferManager::dataCountAngularAcceleration
* Method to get the current count of data into the buffer
* @return {uint8_t} Return the item count
*/
uint8_t BufferManager::dataCountAngularAcceleration()
{
	return dataCount(&bufferAngularAcceleration);
}

/*
* BufferManager::dataCountHumidity
* Method to get the current count of data into the buffer
* @return {uint8_t} Return the item count
*/
uint8_t BufferManager::dataCountHumidity()
{
	return dataCount(&bufferHumidity);
}

/*
* BufferManager::dataCountTemperature
* Method to get the current count of data into the buffer
* @return {uint8_t} Return the item count
*/
uint8_t BufferManager::dataCountTemperature()
{
	return dataCount(&bufferTemperature);
}

/*
* BufferManager::dataCountLight
* Method to get the current count of data into the buffer
* @return {uint8_t} Return the item count
*/
uint8_t BufferManager::dataCountLight()
{
	return dataCount(&bufferLight);
}

/*
* BufferManager::dataCountAlert
* Method to get the current count of data into the buffer
* @return {uint8_t} Return the item count
*/
uint8_t BufferManager::dataCountAlert()
{
	return dataCount(&bufferAlert);
}

/*
* BufferManager::setAlertManager
* Setter for alertManager attribute
* @param {AlertManager*} Pointer to alertManager instance
* @return {void}
*/
void BufferManager::setAlertManager(AlertManager* a)
{
	this->alertManager = a;
}

/*
* BufferManager::getAlertManager
* Getter for alertManager attribute
* @return {AlertManager*}
*/
AlertManager* BufferManager::getAlertManager()
{
	return this->alertManager;
}