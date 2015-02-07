#include <SoftwareSerial.h>

#include <NullStream.h>
#include <TapStream.h>

//you can connect TX and RX pins below together with a wire to
//create a hadware loopback (echo) so you can sniff the reads too
SoftwareSerial mySerial(10, 11); // RX, TX

//You can tap the write implicitly
TapStream tapStream(mySerial, Serial);

//or explicitly
//TapStream tapStream(mySerial, Serial, true);

//or you can tap the read
//TapStream tapStream(mySerial, Serial, false);

//or you can tap both
//TapStream tapStream(mySerial, Serial, Serial);

void setup()  
{
  Serial.begin(57600);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
}

void loop()
{
  //print something into my tapStream, itll get forwarded to
  //mySerial, but will also print to your read write taps
  tapStream.println("Hello, world?");
  delay(2000);
}
