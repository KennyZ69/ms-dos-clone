/* err.h */
#pragma once

#include "os.h"

typedef i8 error;

public packed enum {
	ErrNoErr,
	ErrInit,
	ErrIO,
	ErrBadFd,
	ErrNoMem,
	ErrNotFound,
};

#ifdef Library
	public error errnum;
#else
	extern error errnum;
#endif

#define reterr(arg) do { \
	errnum = (arg); \
	return 0; \
	} while(false)
