CC = powerpc-linux-gnu-gcc
CFLAGS = -Wall -Os

all: xbox_dash.elf

xbox_dash.elf: main.c
	$(CC) $(CFLAGS) main.c -o xbox_dash.elf

clean:
	rm -f *.elf
