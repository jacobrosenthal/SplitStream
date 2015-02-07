#TapStream

Man in the middle reads and writes to an Arduino Stream object. Usefule for logging and debugging. For read and write char, you can enable TAPSTREAM_DEBUG in TapStream.cpp to print as hex with w: or r: prepended before the operation for more useful logging.

##Install
As usual, download zip, unzip and rename to remove the dash character and place in your Arduino Libraries folder, on MacOSX ~/Documents/Arduino/libraries/

##Use
```cpp
//You can tap the write implicitly
TapStream tapStream(mySerial, Serial);

//or explicitly
//TapStream tapStream(mySerial, Serial, true);

//or you can tap the read
//TapStream tapStream(mySerial, Serial, false);

//or you can tap both
//TapStream tapStream(mySerial, Serial, Serial);
```

```cpp
//print something into my tapStream, itll get forwarded to
//mySerial, but will also print to your read write taps
tapStream.println("Hello, world?");
```
