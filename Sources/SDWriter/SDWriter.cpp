#include "SDWriter.h"

/**
* SDWriter
* Overrided constructor
* @param String _groupID
*/
SDWriter::SDWriter(String _groupID)
{
	groupID = _groupID;
	pin = 1;

	pinMode(ledPin, OUTPUT);
	pinMode(interruptPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interruptPin), eraseSD, CHANGE);
}

/**
* SDWriter
* Overrided constructor
* @param {String} _groupID
* @param {int} _pin
*/
SDWriter::SDWriter(String _groupID, int p)
{
	groupID = _groupID;
	pin = p;

	pinMode(ledPin, OUTPUT);
	pinMode(interruptPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interruptPin), eraseSD, CHANGE);
}

/**
* initialize
* Initialize Writter and SD Card behavior
* @return {void}
*/
bool SDWriter::initialize()
{
	Sd2Card card;
	card.init(SPI_HALF_SPEED, pin);

	SdVolume volume;
  	volume.init(card);
  
  	volumesize = volume.blocksPerCluster() * volume.clusterCount() * 512;

	if (!SD.begin(pin))
		state = false;
	else
		state = true;

	return state;
}

/**
* isInitialized
* Check if SD Card and Library are initialized
* @return {bool} state Internal state of the writer
*/
bool SDWriter::isInitialized()
{
	return state;
}

/**
* addToJSONString
* Add key/value to internal json string.
* @param {String} key 	JSON Key to be written
* @param {String} value JSON Value to be written
*/
void SDWriter::addToJSONString(String key, String value)
{
	json += "\"" + key + "\": " + value + ",";
}

/**
* pushToSD
* Push json string in open file.
* @return {void}
*/
void SDWriter::pushToSD()
{	
	if(!openFile)
		changeOpenFile();
	
	bool endOfFile = false;
	
	if(cmp <= MAX_LINE_PER_FILE)
	{
		json = json.substring(0, json.length() - 1) + "},";
	} 
	else
	{
		endOfFile = true;
		json = json.substring(0, json.length() - 1) + "}]}";
	}
	
	if (openFile.print(json))
	{
		openFile.flush();
		++cmp;
	}
	else
	{
		openFile.close();
		state = false;
	}

	json = "{";
	
	
	if(endOfFile)
		changeOpenFile();
}

/**
* changeOpenFile
* Private method to switch the opened file. Close the old file and open new file.
* @return {void}
*/
void SDWriter::changeOpenFile()
{
	if(cmp >= MAX_LINE_PER_FILE)
	{
		totalfilesize += openFile.size();
		openFile.close();
	}
	
	if (openFile = SD.open(generateFileName(), FILE_WRITE))
	{
		openFile.print("{\"DATA\":[");
		cmp = 0;
	}
	else
	{
		openFile.close();
		state = false;
	}
}

/**
* generateFileName
* Private methode generate each file name for the SD file
* @return String filename
*/
String SDWriter::generateFileName()
{
	
	String fileNameID;
	if(fileID >= 100000)
	{
		fileNameID = groupID + String(fileID);
		++fileID;
		return  fileNameID + ".txt" ;
	}
	if(fileID >= 10000)
	{
		fileNameID = groupID + "0" + String(fileID);
		++fileID;
		return  fileNameID + ".txt" ;
	}
	if(fileID >= 1000)
	{	
		fileNameID = groupID + "00" + String(fileID);
		++fileID;
		return  fileNameID + ".txt" ;
	}
	if(fileID >= 100)
	{
		fileNameID = groupID + "000" + String(fileID);
		++fileID;
		return  fileNameID + ".txt" ;
	}
	if(fileID >= 10)
	{
		fileNameID = groupID + "0000" + String(fileID);
		++fileID;
		return  fileNameID + ".txt" ;
	}
	
	fileNameID = groupID + "00000" + fileID;
	++fileID;
	return  fileNameID + ".txt" ;
}

/**
* eraseSD
* Delete SD content
*/
void SDWriter::eraseSD()
{
	File dir = SD.open("/");
	File file;

	digitalWrite(ledPin, HIGH);
    while(true) 
    {
		file = dir.openNextFile();
		if (file) 
		{
			SD.remove(file.name());
			file.close();
		} 
		else 
		{
		  break;
		}
    }
    digitalWrite(ledPin, LOW);
}

/**
 * isSDCardFull
 * Check if SD Card memory is full
 * @return {bool} True if card full or false otherwise
 */
bool SDWriter::isSDCardFull()
{
    if (volumesize - totalfilesize <= 30000000)
    	return true;

    return false;
}

/**
 * isSDCardEmpty
 * Check if SD Card memory is empty
 * @return {bool} True if card empty or false otherwise
 */
bool SDWriter::isSDCardEmpty()
{
	File dir = SD.open("/");
	File entry;

	int32_t filesize;

  	dir.openNextFile();
  	
  	while(entry = dir.openNextFile()) 
    {
      	filesize += entry.size();
      	entry.close();
    }

    if (filesize == 0)
    	return true;

    return false;
}


