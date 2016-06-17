#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

#include "Arduino.h"
#include "AlertManager.h"

/*
* Preprocessor constant to determine the max size of each buffer
* Limited to 200
*/

#define MAXSIZE_GPS 				3
#define MAXSIZE_LINEARACCELERATION 	50
#define MAXSIZE_ANGULARACCELERATION 50
#define MAXSIZE_HUMIDITY			50
#define MAXSIZE_TEMPERATURE			50
#define MAXSIZE_LIGHT				50
#define MAXSIZE_ALERT				50
	
/*
* Structure representing a circular buffer
*/
typedef struct SCircularBuffer
{
	void* buffer;		// Data buffer
	void* bufferEnd;	// End of data buffer
	
	uint8_t capacity;		// Maximum capacity
	uint8_t count;			// Current count of items
	uint8_t itemSize;		// Size of a single item
	
	void* head;			// Pointer to head (cursor to the next writing slot)
	void* tail;			// Pointer to tail (cursor to the next reading slot)
	
} SCircularBuffer;

/*
* BufferManager class
* This class is used to manage buffer pool. Each buffer can store different kind of variable
*/
class BufferManager
{
	public:
		/*
		* Default constructor and destructor
		*/
		BufferManager();
		~BufferManager();
		
		/*
		* Specific push methods
		*/
		void pushGPS(SCoordinate* data);
		void pushLinearAcceleration(SLinearAcceleration* data);
		void pushAngularAcceleration(SAngularAcceleration* data);
		void pushHumidity(SHumidity* data);
		void pushTemperature(STemperature* data);
		void pushLight(SLight* data);
		void pushAlert(SAlert* data);
		
		/*
		* Specific pop methods
		*/
		bool popGPS(SCoordinate* result);
		bool popLinearAcceleration(SLinearAcceleration* result);
		bool popAngularAcceleration(SAngularAcceleration* result);
		bool popHumidity(SHumidity* result);
		bool popTemperature(STemperature* result);
		bool popLight(SLight* result);
		bool popAlert(SAlert* result);
		
		/*
		* Specific checking methods
		*/
		bool dataAvailableGPS();
		bool dataAvailableLinearAcceleration();
		bool dataAvailableAngularAcceleration();
		bool dataAvailableHumidity();
		bool dataAvailableTemperature();
		bool dataAvailableLight();
		bool dataAvailableAlert();
		
		uint8_t dataCountGPS();
		uint8_t dataCountLinearAcceleration();
		uint8_t dataCountAngularAcceleration();
		uint8_t dataCountHumidity();
		uint8_t dataCountTemperature();
		uint8_t dataCountLight();
		uint8_t dataCountAlert();

		/* Getter and setter methods */

		void setAlertManager(AlertManager* a);
		AlertManager* getAlertManager();

	private:
		/*
		* Private attributes, one per datatype to store
		*/
		SCircularBuffer bufferGPS;
		SCircularBuffer bufferLinearAcceleration;
		SCircularBuffer bufferAngularAcceleration;
		SCircularBuffer bufferHumidity;
		SCircularBuffer bufferTemperature;
		SCircularBuffer bufferLight;
		SCircularBuffer bufferAlert;

		AlertManager* alertManager = NULL;

	
		/*
		* Private methods
		* Buffer initialisation and free
		*/
		void bufferInit(SCircularBuffer* cb, uint8_t capacity, uint8_t itemSize);
		void bufferFree(SCircularBuffer* cb);
		
		/*
		* Generic methods to push and pop a buffer
		*/
		void genericPush(SCircularBuffer* cb, void* data);
		bool genericPop(SCircularBuffer* cb, void* item);
		
		/*
		* Generic checking methods
		*/
		bool dataAvailable(SCircularBuffer* cb);
		uint8_t dataCount(SCircularBuffer* cb);	
};

#endif
