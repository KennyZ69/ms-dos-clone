flags = -O2 -Wall -std=c23 -I../osapi
ldflags =

.PHONY: clean

all: clean clean-osapi cmd.com

cmd.com: cmd.o ../osapi/osapi.o
	cc $(flags) $^ -o $@ $(ldflags)

cmd.o: cmd.c cmd.h
	cc $(flags) -c $<

../osapi/osapi.o:
	$(MAKE) -C ../osapi -sk "CFLAGS=$(flags)"

clean-osapi:
	cd ../osapi
	$(MAKE) clean

clean:
	rm -f *.o cmd.com

