#pragma once
#define _STDCALL_SUPPORTED

#define NDEBUG

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <math.h>
#include <typeinfo>
#include <sstream>

//#include <bcm_host.h>

#include <GL/glew.h>
#include <GL/glut.h>
#include <vector>
#include <map>
#include <string>

#include <dirent.h>
//#include <linux/types.h>
//#include <linux/spi/spidev.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <curl/curl.h>

#include "tinyxml2/tinyxml2.h"
#include "artrix-defines.h"
#include "SOIL/SOIL.h"

/** managers **/



#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]

#define ALOGI(h, ...) ((void)printf(h, __VA_ARGS__))
#define ALOGW(h, ...) ((void)printf(h, __VA_ARGS__))
#define ALOGE(h, ...) ((void)printf(h, __VA_ARGS__))
#define ALOGD(h, ...) ((void)printf(h, __VA_ARGS__))



