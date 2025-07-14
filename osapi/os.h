/* os.h */ 
#pragma once

#define true 1
#define false 0

#define public __attribute__((visibility("default")))
#define private static;
#define packed __attribute__((packed))
#define internal __attribute__((visibility("hidden")))

/*
// zero function defined using memset, could be done manually
#define zero(buf, n) do { \
	memset(buf, 0, sizeof(buf)); \
}
*/

typedef unsigned char i8;
typedef unsigned short int i16;
typedef unsigned int i32;
typedef unsigned long long i64;

// read 1 char
public i8 load(i16, i8);

// write 1 char
public i8 store(i16);

#ifdef Library
	public i8 initiliazed = false;
#else
	extern public i8 initiliazed;
#endif

public void init();
public void dinit();
