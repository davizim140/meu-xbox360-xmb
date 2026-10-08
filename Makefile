CC = powerpc-linux-gnu-gcc
CFLAGS = -mcpu=cell -mtune=cell -Os -Wall -I.
LDFLAGS = -g

all: xbox_dash.elf

xbox_dash.elf: main.o
	$(CC) -o $@ $+ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o *.elf
