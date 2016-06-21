#include <RGBLed.h>
RGBLed RGB;
void setup() 
{}

void loop() 
{
  RGB.lightOn(200,0,0);// color RED
  delay(2000);
  RGB.lightOn(180,70,0); //color YELLOW
  delay(2000);
  RGB.lightOn(0,150,0);//color GREEN
  delay(2000);
  RGB.lightOff();
  delay(5000);

}
