#include "SDWriter.h"

/**
* SDWriter
* Overrided constructor
* @param String _groupID
*/
SDWriter::SDWriter(String _groupID)
{
	groupID = _groupID;
	SD.begin(10);
	attachInterrupt(digitalPinToInterrupt(3), eraseSD, RISING);
}

/**
* SDWriter
* Overrided constructor
* @param String _groupID
* 		int _pin
*/
SDWriter::SDWriter(String _groupID,int _pin)
{
	groupID = _groupID;
	SD.begin(_pin);
	attachInterrupt(digitalPinToInterrupt(3), eraseSD, RISING);
}

/**
* changeOpenFile
* Private method to switch the opened file. Close the old file and create need file.
*/
void SDWriter::changeOpenFile()
{
	if(cmp >= 20)
	{
		openFile.close();
	}
	
	openFile = SD.open(generateFileName(),FILE_WRITE);
	openFile.println("{\"DATA\":[");
	cmp = 0;
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
* addToJSONString
* Add key/value to internal json string.
* @param String key
* 		String value
*/
void SDWriter::addToJSONString(String key,String value)
{
	json += "\""+key+"\": "+value+",";
}

/**
* pushToSD
* Push json string in open file.
*/
void SDWriter::pushToSD()
{
	if(erase)
		return;
	
	if(!openFile)
		changeOpenFile();
	
	bool endOfFile = false;
	
	if(cmp <= 20)
	{
		json = json.substring(0, json.length() - 1) +"},";
	} 
	else
	{
		endOfFile = true;
		json = json.substring(0, json.length() - 1) +"}]}";
	}
	
	openFile.println(json);
	openFile.flush();
	json = "{";
	++cmp;
	
	if(endOfFile)
		changeOpenFile();
}

/**
* eraseSD
* Delete SD content
*/
void SDWriter::eraseSD()
{
	erase = true;
	File dir = SD.open("/");
	File file;

    while(true) 
    {
		file =  dir.openNextFile();
		if (file) 
		{
			SD.remove( file.name() ) ;
		} 
		else 
		{
		  break;
		}
		
    }
	// TO DO
	openFile.close();
	SD.remove (openFile.name());
	//
	erase = false;
}

