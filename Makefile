PROJECT := qr430
SOURCES := main.c version7H.c qrencode.c
MCU := msp430fr5739

CC := msp430-gcc
CFLAGS := -O2 -mmcu=$(MCU)
LDFLAGS :=
LDLIBS :=

OBJECTS := $(SOURCES:%.c=%.o)

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(PROJECT)

clear:
	clear

.PHONY: clean clear

