#include <TapStream.h>

TapStream::TapStream(Stream &source)
  : source(&source)
  , writes(&nullStream)
  , reads(&nullStream)
{}

TapStream::TapStream(Stream &source, Stream &stream, bool tapWrite) {
  this->source = &source;
  if (tapWrite) {
    this->writes = &stream;
    this->reads = &nullStream;
  } else {
    this->writes = &nullStream;
    this->reads = &stream;
  }
}

TapStream::TapStream(Stream &source, Stream &writes, Stream &reads)
  : source(&source)
  , writes(&writes)
  , reads(&reads)
{}

TapStream::~TapStream() {
  this->source = 0;
  this->writes = 0;
  this->reads = 0;
}

void TapStream::stopRead() {
  this->reads = &this->nullStream;
}

void TapStream::stopWrite() {
  this->writes = &this->nullStream;
}

void TapStream::setRead(Stream &_stream) {
  this->reads = &_stream;
}

void TapStream::setWrite(Stream &_stream) {
  this->writes = &_stream;
}

void TapStream::setSource(Stream &_stream) {
  this->source = &_stream;
}

int TapStream::available() {
  return source->available();
}

int TapStream::peek() {
  return source->peek();
}

void TapStream::flush() {
  writes->flush();
  source->flush();
}

int TapStream::read() {
  int c = source->read();
  reads->write(c);
  return c;
}

size_t TapStream::write(uint8_t c) {
  writes->write(c);
  return source->write(c);
}

size_t TapStream::write(const uint8_t *buffer, size_t size) {
  size_t n = 0;
  while (size--) {
    writes->write(*buffer);
    n += source->write(*buffer++);
  }
  return n;
}
