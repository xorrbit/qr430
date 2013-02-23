PROJECT := qr430
SOURCES := main.c qrencode.c version74.c pcd8544.c
MCU := msp430fr5739

CC := msp430-gcc
CFLAGS := -mmcu=$(MCU) -DUSEPRECALC
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
