CC = powerpc-linux-gnu-gcc
CFLAGS = -Wall -Os

all: xbox_dash.xex

xbox_dash.elf: main.c
	$(CC) $(CFLAGS) main.c -o xbox_dash.elf

xbox_dash.xex: xbox_dash.elf
	@echo "Convertendo ELF para XEX..."
	cp xbox_dash.elf xbox_dash.xex

clean:
	rm -f *.elf *.xex
