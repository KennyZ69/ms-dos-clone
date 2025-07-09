/* err.h */

#include "os.h"

typedef i8 error;

#define ErrBadFD 8

error errnum;

#define reterr(arg) do { \
	errnum = (arg); \
	return 0; \
	} while(false)

