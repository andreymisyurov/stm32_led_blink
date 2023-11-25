CC=arm-none-eabi-gcc

all: sturtup.o main.o delay.o
	arm-none-eabi-gcc -o fw.elf sturtup.o main.o delay.o -Tlinker.ld -Wl,--gc-sections -nostartfiles -nodefaultlibs -nostdlib
	arm-none-eabi-objcopy -O binary fw.elf fw.bin

sturtup.o: sturtup.c
	$(CC) -c sturtup.c -o sturtup.o -mthumb -ffreestanding

main.o: main.c
	$(CC) -c main.c -o main.o -mthumb -ffreestanding

delay.o: delay.c
	$(CC) -c delay.c -o delay.o -mthumb -ffreestanding

flash:
	st-info --probe
	st-flash write fw.bin 0x8000000

clean:
	rm *.o fw.bin fw.elf
