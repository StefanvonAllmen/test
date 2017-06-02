#include <Wire.h>
void setup()
{
  Wire.begin();      
  Serial.begin(9600);
}
int Aout = 0;
void loop()
{
  int pot = readWire(72,0x41);
  int temp = readWire(72,0x42);
  int light = readWire(72,0x43);
  int ch4 = readWire(72,0x44);
  Serial.print(pot,DEC);
  Serial.print("\t");
  Serial.print(temp,DEC);
  Serial.print("\t");
  Serial.print(light,DEC);
  Serial.print("\t");
  Serial.println(ch4,DEC);
  if (Aout < 250)    Aout += 10;
  else               Aout = 0;
  writeWire(72,0x40,Aout);
  delay(100);
}
int readWire(int device, int channel)
{
  int retval;
  Wire.beginTransmission(device);
  Wire.write(channel);
  Wire.endTransmission();
  Wire.requestFrom(device, 6);  
  while (Wire.available()) {
    retval = Wire.read();
  }
  return retval;
}
void writeWire(int device, int channel, int value)
{
  Wire.beginTransmission(device);
  Wire.write(channel);
  Wire.write(value);
  Wire.endTransmission();
}
