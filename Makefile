CC=arm-none-eabi-gcc
SRC=./source
INC=-I./include

all: sturtup.o main.o delay.o
	arm-none-eabi-gcc -o fw.elf sturtup.o main.o delay.o -Tlinker.ld -Wl,--gc-sections -nostartfiles -nodefaultlibs -nostdlib
	arm-none-eabi-objcopy -O binary fw.elf fw.bin

flash:
	st-info --probe
	st-flash write fw.bin 0x8000000

clean:
	rm -rf *.o *.bin *.elf

sturtup.o: $(SRC)/sturtup.c
	$(CC) -c $(SRC)/sturtup.c -o sturtup.o -mthumb $(INC)

main.o: $(SRC)/main.c
	$(CC) -c $(SRC)/main.c -o main.o -mthumb $(INC)

delay.o: $(SRC)/delay.c
	$(CC) -c $(SRC)/delay.c -o delay.o -mthumb $(INC)