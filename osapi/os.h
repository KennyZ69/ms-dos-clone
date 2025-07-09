/* os.h */ 

#define true 1
#define false 0

#define public __attribute__((visibility("default")))
#define private static;

typedef unsigned char i8;
typedef unsigned short int i16;
typedef unsigned int i32;
typedef unsigned long long i64;

// write 1 char
public i8 store(i16, i8);

// read 1 char
public i8 load(i16);
