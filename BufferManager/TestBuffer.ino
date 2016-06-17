#include "BufferManager.h"


/*
 * Initializing buffer manager
 */
BufferManager bm;

/*
 * Simulated data for test
 */
SCoordinate data1;
SCoordinate data2;
SCoordinate data3;
SCoordinate data4;

SHumidity dataH1;
SHumidity dataH2;
SHumidity dataH3;
SHumidity dataH4;

SLight dataL1;
SLight dataL2;
SLight dataL3;
SLight dataL4;

/*
 * Result structure to test pop feature
 */
SCoordinate result;
SHumidity resultH;
SLight resultL;


void setup() 
{
  /*
   * Serial init
   */
  Serial.begin(9600);

  /*
   * Test data setting
   */
  data1.id = 101;
  data2.id = 102;
  data3.id = 103;
  data4.id = 104;

  dataH1.id = 365;
  dataH2.id = 366;
  dataH3.id = 367;
  dataH4.id = 368;

  dataL1.id = 365;
  dataL2.id = 366;
  dataL3.id = 367;
  dataL4.id = 368;
  

  /*
   * Push test data into buffers
   * The max size of GPS buffer is set to 3, to test the erasing oldest data feature
   */
  bm.pushGPS(&data1);
  bm.pushHumidity(&dataH1);
  bm.pushGPS(&data2);
  bm.pushHumidity(&dataH2);
  bm.pushGPS(&data3);
  bm.pushHumidity(&dataH3);
  bm.pushGPS(&data4);
  bm.pushHumidity(&dataH4);
  bm.pushLight(&dataL1);
  bm.pushLight(&dataL2);
  bm.pushLight(&dataL3);
  bm.pushLight(&dataL4);


  /*
   * Reading loop for Light data
   * Trying to get 5 result, despite only 4 were pushed, to test the empty buffer case
   */
  for(int i = 0; i < 5; i++)
  {
    Serial.println(bm.dataAvailableLight() ? "Data available" : "No data available");
    Serial.print("Light ");
    Serial.print(i);
    Serial.print(" : ");
    
    if(bm.popLight(&resultL))
    {
      Serial.println(resultL.id);
      Serial.print("CurrentCount : ");
      Serial.println(bm.dataCountLight());
    }
    else
    {
      Serial.println("false");
    }
   }

   
  /*
   * Reading loop for GPS data
   * Trying to get 5 result, despite only 4 were pushed, to test the empty buffer case
   */
  for(int i = 0; i < 5; i++)
  {
    Serial.println(bm.dataAvailableGPS() ? "Data available" : "No data available");
    Serial.print("GPS ");
    Serial.print(i);
    Serial.print(" : ");
    
    if(bm.popGPS(&result))
    {
      Serial.println(result.id);
      Serial.print("CurrentCount : ");
      Serial.println(bm.dataCountGPS());
    }
    else
    {
      Serial.println("false");
    }
   }


   

  
  /*
   * Reading loop for GPS data from buffer
   * Trying to get 5 result, despite only 4 were pushed, to test the empty buffer case
   */
  for(int i = 0; i < 5; i++)
  {
    Serial.println(bm.dataAvailableHumidity() ? "Data available" : "No data available");
    Serial.print("Humidity ");
    Serial.print(i);
    Serial.print(" : ");
    
      if(bm.popHumidity(&resultH))
      {
        Serial.println(resultH.id);
        Serial.print("CurrentCount : ");
        Serial.println(bm.dataCountHumidity());
      }
      else
      {
        Serial.println("false");
      }
   }
    
}
  

void loop() {
  // Nothing here

}
