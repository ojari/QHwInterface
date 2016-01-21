#ifndef CONFIG_H
#define CONFIG_H

#include <QtCore/QDebug>

#define PORT_NUMBER 8001
#define READ_DELAY  10000 // milli seconds

#define LINUX

#ifdef LINUX
  #define RS_PORT "/dev/ttyS0"
#else
  #define RS_PORT "COM1"
#endif

#endif // CONFIG_H
