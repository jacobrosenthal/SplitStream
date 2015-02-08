#include <TapStream.h>

// #define TAPSTREAM_DEBUG 1

TapStream::TapStream(Stream &_source) {

  this->source = &_source;
  this->writes = &this->nullStream;
  this->reads = &this->nullStream;
}

TapStream::TapStream(Stream &_source, Stream &_stream, bool tapWrite) {

  this->source = &_source;
  if (tapWrite) {
    this->writes = &_stream;
    this->reads = &this->nullStream;
  } else {
    this->writes = &this->nullStream;
    this->reads = &_stream;
  }
}

TapStream::TapStream(Stream &_source, Stream &_writes, Stream &_reads) {

  this->source = &_source;
  this->writes = &_writes;
  this->reads = &_reads;
}

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

int TapStream::peek()
{
  return source->peek();
}

void TapStream::flush()
{
  writes->flush();
  source->flush();
}

int TapStream::read() {
  int c = source->read();
#ifdef TAPSTREAM_DEBUG
  reads->print("r: ");
  reads->println(c, HEX);
#else
  reads->write(c);
#endif
  return c;
}

size_t TapStream::write(uint8_t c)
{
#ifdef TAPSTREAM_DEBUG
  writes->print("w: ");
  writes->println(c, HEX);
#else
  writes->write(c);
#endif
  return source->write(c);
}

size_t TapStream::write(const char *str) {
  if (str == NULL) return 0;
  writes->write((const uint8_t *)str, strlen(str));
  return source->write((const uint8_t *)str, strlen(str));
}

size_t TapStream::write(const char *buffer, size_t size) {
  writes->write((const uint8_t *)buffer, size);
  return source->write((const uint8_t *)buffer, size);
}

size_t TapStream::write(const uint8_t *buffer, size_t size)
{
  size_t n = 0;
  while (size--) {
    writes->write(*buffer);
    n += source->write(*buffer++);
  }
  return n;
}

size_t TapStream::print(const __FlashStringHelper *ifsh)
{
  writes->print(ifsh);
  return source->print(ifsh);
}

size_t TapStream::print(const String &s)
{
  writes->print(s);
  return source->print(s);
}

size_t TapStream::print(const char str[])
{
  writes->print(str);
  return source->print(str);
}

size_t TapStream::print(char c)
{
  writes->print(c);
  return source->print(c);
}

size_t TapStream::print(unsigned char b, int base)
{
  writes->print(b, base);
  return source->print(b, base);
}

size_t TapStream::print(int n, int base)
{
  writes->print(n, base);
  return source->print(n, base);
}

size_t TapStream::print(unsigned int n, int base)
{
  writes->print(n, base);
  return source->print(n, base);
}

size_t TapStream::print(long n, int base)
{
  writes->print(n, base);
  return source->print(n, base);
}

size_t TapStream::print(unsigned long n, int base)
{
  writes->print(n, base);
  return source->print(n, base);
}

size_t TapStream::print(double n, int digits)
{
  writes->print(n, digits);
  return source->print(n, digits);
}

size_t TapStream::println(const __FlashStringHelper *ifsh)
{
  writes->println(ifsh);
  return source->println(ifsh);
}

size_t TapStream::print(const Printable &x)
{
  writes->print(x);
  return source->print(x);
}

size_t TapStream::println(void)
{
  writes->println();
  return source->println();
}

size_t TapStream::println(const String &s)
{
  writes->println(s);
  return source->println(s);
}

size_t TapStream::println(const char c[])
{
  writes->println(c);
  return source->println(c);
}

size_t TapStream::println(char c)
{
  writes->println(c);
  return source->println(c);
}

size_t TapStream::println(unsigned char b, int base)
{
  writes->println(b, base);
  return source->println(b, base);
}

size_t TapStream::println(int num, int base)
{
  writes->println(num, base);
  return source->println(num, base);
}

size_t TapStream::println(unsigned int num, int base)
{
  writes->println(num, base);
  return source->println(num, base);
}

size_t TapStream::println(long num, int base)
{
  writes->println(num, base);
  return source->println(num, base);
}

size_t TapStream::println(unsigned long num, int base)
{
  writes->println(num, base);
  return source->println(num, base);
}

size_t TapStream::println(double num, int digits)
{
  writes->println(num, digits);
  return source->println(num, digits);
}

size_t TapStream::println(const Printable &x)
{
  writes->println(x);
  return source->println(x);
}