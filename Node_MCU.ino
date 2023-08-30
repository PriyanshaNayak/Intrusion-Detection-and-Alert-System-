#include<SoftwareSerial.h>

int led = 10;
int received = 0;
int i;

//For communicating with zigbee
SoftwareSerial zigbee(13,12);

void setup()
{
    Serial.begin(9600);
    zigbee.begin(9600);
    pinMode(led, OUTPUT);

}

void loop()
{
    //check if the data is received 
    if (zigbee.available() > 0)
    {
        received = zigbee.read();
        if (received == '0')
        {
            Serial.println("0");
            digitalWrite(led, LOW);
            delay(10);
        }
        if the data is 1, turn on the LED
        else if (received == '1')
        {
            Serial.println("1");
            digitalWrite(led, HIGH);
            delay(10);
        }
        else
        {
          Serial.println("2");
            digitalWrite(led, HIGH);
        }
    }
}