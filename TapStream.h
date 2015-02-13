#ifndef TapStream_h
#define TapStream_h

#include "Arduino.h"
#include <NullStream.h>

class TapStream : public Stream {
  public:
    TapStream(Stream &source);
    TapStream(Stream &source, Stream &stream, bool tapWrite = true);
    TapStream(Stream &source, Stream &writes, Stream &reads);
    ~TapStream();

    void stopRead();
    void stopWrite();
    void setRead(Stream &_stream);
    void setWrite(Stream &_stream);
    void setSource(Stream &_stream);

    int available();
    int peek();
    void flush();

    int read();

    size_t write(uint8_t c);
    size_t write(const uint8_t *buffer, size_t size);

  private:
    NullStream nullStream;
    Stream *source;
    Stream *writes;
    Stream *reads;
};

#endif // TapStream_h