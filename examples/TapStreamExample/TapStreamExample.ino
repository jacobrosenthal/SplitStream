#include <SoftwareSerial.h>
#include <TapStream.h>

//connect TX and RX below together with a wire to
//create a hadware loopback (echo)
SoftwareSerial mySerial(10, 11); // RX, TX

//source, writes, reads
TapStream tapStream(mySerial, Serial, Serial);

void setup()  
{
  Serial.begin(57600);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);

  //print something into my tapStream, itll get forwarded to
  //mySerial, but will also print to Serial twice, once for
  //read and once for write
  tapStream.println("Hello, world?");
}

void loop()
{
}
