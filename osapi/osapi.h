/* osapi.h */
#pragma once

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "os.h"
#include "err.h"

i16 fds[256]; // list of possible file descriptors - global

#define getposixfd(arg) fds[(arg)]

#ifdef Library 
	private i8 isopen(i16);
	private void setupfds(void);
#endif

private void zero(i8*, i16);
