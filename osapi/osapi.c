/* osapi.c */
#define Library
#include "osapi.h"

private i8 isopen(i16 fd) {
	signed int posixfd;

	if (fd < 3) { // fd=1 -> stdin ; fd=2 -> stdout ; fd=0 -> error
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

public i8 load(i16 fd, i8 c) {
	i8 buf[2];
	signed int n;
	signed int posixfd;
	if (fd > 1) {
		if (!isopen(fd)) {
			reterr(ErrBadFD);
		}
	}

	posixfd = getposixfd(fd);
	if (!posixfd) {
		reterr(ErrBadFD);
	}
	posixfd = (posixfd == 1) ? 0
		: (posixfd == 2) ? 1
		: (posixfd);

	*buf = c;
	n = read(posixfd, (char *)buf, 1);
	if (n != 1) {
		reterr(ErrIO);
	}

	return true;
}

public i8 store(i16 fd) {
	i8 buf[2];
	signed int n;
	signed int posixfd;
	if (fd > 2) {
		if (!isopen(fd)) {
			reterr(ErrBadFD);
		}
	}

	posixfd = getposixfd(fd);
	if (!posixfd) {
		reterr(ErrBadFD);
	}

	*buf = *(buf+1) = (i8)0; // initiliaze the buffer with zero on both bytes
	n = read(posixfd, (char *)buf, 1);
	if (n != 1) {
		reterr(ErrIO);
	}

	return (i8)*buf;
}

private void setupfds() {
	zero(fds, sizeof(fds));

	fds[0] = 1;
	fds[1] = 2;

	return;
}

private void zero(i8 *buf, i16 size) {
	i16 n;
	i8 *p;

	for (n = size, p=buf; n; n--, p++) { // till n is different from zero
		*p = (i8)0;
	}

	return;
}

private void init() {
	setupfds();

	initiliazed = true;

	return;
}
