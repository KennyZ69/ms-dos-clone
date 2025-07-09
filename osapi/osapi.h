#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "os.h"
#include "err.h"

i16 fds[256]; // list of possible file descriptors

#define getposixfd(arg) fds[(arg)]

// private i8 isopen(i16);
