#include "gtest/gtest.h"
#include "Arduino.h"
#include "Serial.h"

#include "TapStream.h"
#include "NullStream.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Matcher;
using ::testing::AtLeast;
using ::testing::Invoke;
using ::testing::InSequence;
using ::testing::TypedEq;


// static size_t println(int, int = DEC);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrintln1) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
	TapStream tapStream(Serial, nullStream, nullStream);
	{
	  InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>(0x31)))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\r')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\n')))
		.WillOnce(Return(1));
	}
  EXPECT_EQ(3, tapStream.println(1, 10));
  releaseSerialMock();
}

// static size_t println(const char[]);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrintln2) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('h')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('a')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('h')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('a')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\r')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\n')))
		.WillOnce(Return(1));
  }
  const char lala[] = "haha";
  EXPECT_EQ(6, tapStream.println(lala));
  releaseSerialMock();
}

// static size_t println(char);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrintln3) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('a')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\r')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\n')))
		.WillOnce(Return(1));
  }
  char lala = 'a';
  EXPECT_EQ(3, tapStream.println(lala));
  releaseSerialMock();
}

// // // XXX print 97rn?
// // // static size_t println(unsigned char, int = DEC);
// // TEST(TapStream, writeSourcePrintln4) {
// //   NullStream nullStream;
// //   SerialMock* serialMock = serialMockInstance();
// //   TapStream tapStream(Serial, nullStream, nullStream);
// //   {
// //     InSequence dummy;
// // 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('a')))
// // 		.WillOnce(Return(1));
// // 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('\r')))
// // 		.WillOnce(Return(1));
// // 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('\n')))
// // 		.WillOnce(Return(1));
// //   }
// //   unsigned char lala = 'a';
// //   EXPECT_EQ(3, tapStream.println(lala));
// // }

// static size_t println(unsigned int, int = DEC);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrintln5) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('1')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('2')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('4')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\r')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\n')))
		.WillOnce(Return(1));
  }
  unsigned int lala = 1234;
  EXPECT_EQ(6, tapStream.println(lala, DEC));
  releaseSerialMock();
}

// static size_t println(long, int = DEC);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrintln6) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('1')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('2')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('4')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('5')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('6')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('7')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\r')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\n')))
		.WillOnce(Return(1));
  }
  long lala = 1234567;
  EXPECT_EQ(9, tapStream.println(lala, DEC));
  releaseSerialMock();
}

// static size_t println(unsigned long, int = DEC);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrintln7) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('2')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('4')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('5')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('6')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('7')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('8')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\r')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\n')))
		.WillOnce(Return(1));
  }
  unsigned long lala = 2345678;
  EXPECT_EQ(9, tapStream.println(lala, DEC));
  releaseSerialMock();
}

// static size_t println(double, int = 2);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrintln8) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('.')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('1')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('4')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\r')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\n')))
		.WillOnce(Return(1));
  }
  double lala = 3.14;
  EXPECT_EQ(6, tapStream.println(lala, 2));
  releaseSerialMock();
}

// static size_t println(void);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrintln9) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\r')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('\n')))
		.WillOnce(Return(1));
  }
  EXPECT_EQ(2, tapStream.println());
  releaseSerialMock();
}

// static size_t print(int, int = DEC);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrint1) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('1')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('2')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
  }
  int lala = 123;
  EXPECT_EQ(3, tapStream.print(lala, 10));
  releaseSerialMock();
}

// // static size_t print(const char[]);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrint2) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('h')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('a')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('h')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('a')))
		.WillOnce(Return(1));
  }
  const char lala[] = "haha";
  EXPECT_EQ(4, tapStream.print(lala));
  releaseSerialMock();
}

// static size_t print(char);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrint3) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
	EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('a')))
	.WillOnce(Return(1));
  char lala = 'a';
  EXPECT_EQ(1, tapStream.print(lala));
  releaseSerialMock();
}

// // XXX 97?
// static size_t print(unsigned char, int = DEC);
// TEST(TapStream, writeSourcePrint4) {
//   NullStream nullStream;
//   SerialMock* serialMock = serialMockInstance();
//   TapStream tapStream(Serial, nullStream, nullStream);
// 	EXPECT_CALL(Serial, write('a'))
// 	.WillOnce(Return(1));
//   unsigned char lala = 'a';
//   EXPECT_EQ(1, tapStream.print(lala));
// }

//static size_t print(unsigned int, int = DEC);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrint5) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('1')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('2')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('4')))
		.WillOnce(Return(1));
  }
  unsigned int lala = 1234;
  EXPECT_EQ(4, tapStream.print(lala, DEC));
  releaseSerialMock();
}

// static size_t print(long, int = DEC);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrint6) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('1')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('2')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('4')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('5')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('6')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('7')))
		.WillOnce(Return(1));
  }
  long lala = 1234567;
  EXPECT_EQ(7, tapStream.print(lala, DEC));
  releaseSerialMock();
}

// static size_t print(unsigned long, int = DEC);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrint7) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('2')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('4')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('5')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('6')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('7')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('8')))
		.WillOnce(Return(1));
  }
  unsigned long lala = 2345678;
  EXPECT_EQ(7, tapStream.print(lala, DEC));
  releaseSerialMock();
}

// static size_t println(double, int = 2);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourcePrint8) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
  {
    InSequence dummy;
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('3')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('.')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('1')))
		.WillOnce(Return(1));
		EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('4')))
		.WillOnce(Return(1));
  }
  double lala = 3.14;
  EXPECT_EQ(4, tapStream.print(lala, 2));
  releaseSerialMock();
}

// size_t write(uint8_t);
//should write to the source and deliver and the writes stream
TEST(TapStream, writeSourceWrite1) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
	EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('a')))
	.WillOnce(Return(1));
  EXPECT_EQ(1, tapStream.write('a'));
  releaseSerialMock();
}

// // write(const uint8_t *buffer)
// // size_t write(const char *str)
// TEST(TapStream, writeSourceWrite6) {
//   NullStream nullStream;
//   SerialMock* serialMock = serialMockInstance();
//   TapStream tapStream(Serial, nullStream, nullStream);
//   {
//     InSequence dummy;
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('a')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('b')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('c')))
// 		.WillOnce(Return(1));
//   }
//   EXPECT_EQ(3, tapStream.write("abc"));
// }

// TEST(TapStream, writeSourceWrite7) {
//   NullStream nullStream;
//   SerialMock* serialMock = serialMockInstance();
//   TapStream tapStream(Serial, nullStream, nullStream);
//   {
//     InSequence dummy;
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('a')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('b')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('c')))
// 		.WillOnce(Return(1));
//   }
//   char lala[] = { 'h', 'a', 'h', 'a', '\0' }; 

//   EXPECT_EQ(3, tapStream.write(lala, 5));
// }


//XXX 
// size_t write(unsigned long n) { return write((uint8_t)n); }
// TEST(TapStream, writeSourceWrite2) {
//   NullStream nullStream;
//   SerialMock* serialMock = serialMockInstance();
//   TapStream tapStream(Serial, nullStream, nullStream);
//   unsigned long lala = 2345678;
//   {
//     InSequence dummy;
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('2')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('3')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('4')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('5')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('6')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('7')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('8')))
// 		.WillOnce(Return(1));
//   }
//   EXPECT_EQ(7, tapStream.write(lala));
// }

//XXX
// size_t write(long n) { return write((uint8_t)n); }
// TEST(TapStream, writeSourceWrite3) {
//   NullStream nullStream;
//   SerialMock* serialMock = serialMockInstance();
//   TapStream tapStream(Serial, nullStream, nullStream);
//   long lala = 1234567;
//   {
//     InSequence dummy;
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('1')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('2')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('3')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('4')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('5')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('6')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('7')))
// 		.WillOnce(Return(1));
//   }
//   EXPECT_EQ(7, tapStream.write(lala));
// }



//XXX
// size_t write(unsigned int n) { return write((uint8_t)n); }
// TEST(TapStream, writeSourceWrite4) {
//   NullStream nullStream;
//   SerialMock* serialMock = serialMockInstance();
//   TapStream tapStream(Serial, nullStream, nullStream);
//   {
//     InSequence dummy;
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('1')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('2')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('3')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('4')))
// 		.WillOnce(Return(1));
//   }
//   unsigned int lala = 1234;
//   EXPECT_EQ(4, tapStream.write(lala));
// }

///XXX
// size_t write(int n) { return write((uint8_t)n); }
// TEST(TapStream, writeSourceWrite5) {
//   NullStream nullStream;
//   SerialMock* serialMock = serialMockInstance();
//   TapStream tapStream(Serial, nullStream, nullStream);
//   {
//     InSequence dummy;
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('1')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('2')))
// 		.WillOnce(Return(1));
// 		EXPECT_CALL(Serial, write(TypedEq<uint8_t>('3')))
// 		.WillOnce(Return(1));
//   }
//   int lala = 123;
//   EXPECT_EQ(1, tapStream.write(lala));
// }


//should read the source and deliver it to the reads stream
TEST(TapStream, read) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, Serial);
	EXPECT_CALL(*serialMock, read())
	.WillOnce(Return('a'));
	EXPECT_CALL(*serialMock, write(TypedEq<uint8_t>('a')))
	.WillOnce(Return(1));
  EXPECT_EQ('a', tapStream.read());
  releaseSerialMock();
}

//should ask source for available byte
TEST(TapStream, available) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
	EXPECT_CALL(*serialMock, available())
	.WillOnce(Return(1));
  EXPECT_EQ(1, tapStream.available());
  releaseSerialMock();
}

//should ask source for peek byte
TEST(TapStream, peek) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, nullStream, nullStream);
	EXPECT_CALL(*serialMock, peek())
	.WillOnce(Return('a'));
  EXPECT_EQ('a', tapStream.peek());
  releaseSerialMock();
}

//should flush source and writes stream
TEST(TapStream, flush) {
  NullStream nullStream;
  SerialMock* serialMock = serialMockInstance();
  TapStream tapStream(Serial, Serial, nullStream);
  EXPECT_CALL(*serialMock, flush())
  .Times(2);
  tapStream.flush();
  releaseSerialMock();
}
