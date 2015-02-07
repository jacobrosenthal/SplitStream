#TapStream

Man in the middle reads and writes to an Arduino Stream object. Usefule for logging and debugging. For read and write char, you can enable TAPSTREAM_DEBUG in TapStream.cpp to print as hex with w: or r: prepended before the operation for more useful logging.

##Install
As usual, download zip, unzip and rename to remove the dash character and place in your Arduino Libraries folder, on MacOSX ~/Documents/Arduino/libraries/

##Use
Create a tap by providing a source stream to forward all calls to, and a write and read stream to forward those operations to as well.
```cpp
TapStream tapStream(mySerial, Serial, Serial);
```

Now reads and writes to mySerial will be pushed to Serial as well.
```cpp
tapStream.write('a');
```
