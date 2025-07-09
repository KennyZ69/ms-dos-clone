flags = -O2 -Wall -std=c23 -I../osapi
ldflags =

.PHONY: clean

all: clean ../osapi/osapi.o cmd.com

cmd.com: cmd.o ../osapi/osapi.o
	cc $(flags) $^ -o $@ $(ldflags)

cmd.o: cmd.c cmd.h
	cc $(flags) -c $< -o $@

../osapi/osapi.o:
	$(MAKE) -C ../osapi

clean:
	rm -f *.o cmd.com

