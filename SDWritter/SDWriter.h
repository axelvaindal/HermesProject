#ifndef SDWRITER_H
#define SDWRITER_H

#include "Arduino.h"
#include "SD.h"

class SDWriter
{
private:
	String json = "{";
	String groupID = "";
	File openFile;
	int8_t cmp = 0;
	long fileID = 1;
	bool erase = false;

	void changeOpenFile();
	String generateFileName();
public:
	SDWriter(String _groupID);
	SDWriter(String _groupID,int _pin);
	
	void pushToSD();
	void addToJSONString(String key,String value);
	void eraseSD();
};

#endif
