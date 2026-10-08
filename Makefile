CC = powerpc-linux-gnu-gcc
CFLAGS = -mcpu=cell -mtune=cell -Os -Wall -I.
LDFLAGS = -g

all: xbox_dash.elf xbox_dash.xex

xbox_dash.elf: main.c
	$(CC) $(CFLAGS) main.c -o xbox_dash.elf $(LDFLAGS)

xbox_dash.xex: xbox_dash.elf
	@echo "Estruturando formato executavel para console..."
	cp xbox_dash.elf xbox_dash.xex

clean:
	rm -f *.elf *.xex
