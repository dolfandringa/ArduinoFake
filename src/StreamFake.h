#ifndef STREAM_FAKE_H
#define STREAM_FAKE_H

#include "ArduinoFake.h"
#include "PrintFake.h"
#include "arduino/Stream.h"

#ifndef NO_IGNORE_CHAR
  #define NO_IGNORE_CHAR  '\x01' // a char not found in a valid ASCII numeric field
#endif

struct StreamFake : public PrintFake
{
    virtual int available() = 0;
    virtual int read() = 0;
    virtual int peek() = 0;
    virtual void flush() = 0;

    virtual void setTimeout(unsigned long timeout) = 0;
    virtual unsigned long getTimeout(void) = 0;

    virtual bool find(char *target) = 0;

    virtual bool find(char *target, size_t length) = 0;

    virtual bool findUntil(char *target, char *terminator) = 0;

    virtual bool findUntil(char *target, size_t targetLen, char *terminate, size_t termLen) = 0;

    virtual long parseInt(LookaheadMode lookahead = SKIP_ALL, char ignore = NO_IGNORE_CHAR) = 0;

    virtual float parseFloat(LookaheadMode lookahead = SKIP_ALL, char ignore = NO_IGNORE_CHAR) = 0;

    virtual size_t readBytes(char *buffer, size_t length) = 0;

    virtual size_t readBytesUntil(char terminator, char *buffer, size_t length) = 0;

    virtual String readString() = 0;
    virtual String readStringUntil(char terminator) = 0;
};

#endif // STREAM_FAKE_H