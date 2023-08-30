#include "SoftwareSerial.h"

	SoftwareSerial XBee(2,3);

	void setup()	
	{
	    Serial.begin(9600);
	    XBee.begin(9600);
	}
	int p=0,q=0,t=0;
	void loop()
	{
    int i=0;
    {
    for(i=0;i<=100;i++)
	   {
      int c=analogRead(A0);
	    int d=abs(c-p);
	    p=c;
	    Serial.println(c);
	    if (d>1)
	    {
	        t++;
	    }
     }
      {
        XBee.write(t);
        if(t>1 && t<30)
        XBee.write('1');
        else if(t>30)
        XBee.write('2');
        else
        XBee.write('0');
        t=0;  
      }
    }
  	}