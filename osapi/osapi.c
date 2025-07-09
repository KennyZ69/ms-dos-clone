/* osapi.c */

#include "osapi.h"

private i8 isopen(i16 fd) {
	signed int posixfd;

	if (fd < 2) {
		return false;
	}

	posixfd = getposixfd(fd);
	if (posixfd == -1) { // is zero
		return false;
	}

	if (fstat(posixfd, NULL) == -1) {
		return false;
	}

	return true;
}

public i8 store(i16 fd, i8 c) {
	if (fd > 1) {
		if (!isopen(fd)) {
			reterr(ErrBadFD);
		}
	}
	return true;
}
