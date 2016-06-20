#ifndef SDWRITER_H
#define SDWRITER_H

#include "Arduino.h"
#include "SD.h"

/**
* Preprocessor Constant to define max number of line per file
*/

#define MAX_LINE_PER_FILE 20

class SDWriter
{
	public:

		SDWriter(String _groupID);
		SDWriter(String _groupID, int p);

		static void eraseSD();
		void pushToSD();
		bool initialize();
		bool isSDCardFull(); 
		bool isSDCardEmpty();
		bool isInitialized();
		void addToJSONString(String key,String value);
		void(* raz) (void) = 0;

	private:

		int pin;

		File openFile;
		int8_t cmp = 0;
		long fileID = 1;
		String json = "{";
		bool state = false;
		String groupID = "";
		uint32_t volumesize;
		uint32_t totalfilesize;
		const byte interruptPin = 3;
		static const byte ledPin = 1;		
		
		void changeOpenFile();
		String generateFileName();
};

#endif
