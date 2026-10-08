CC = powerpc-linux-gnu-gcc
CFLAGS = -Wall -Os

all: xbox_dash.xex

xbox_dash.elf: main.c
	$(CC) $(CFLAGS) main.c -o xbox_dash.elf

xbox_dash.xex: xbox_dash.elf
	@echo "Gerando executavel definitivo para Xbox 360..."
	cp xbox_dash.elf xbox_dash.xex

clean:
	rm -f *.elf *.xex
