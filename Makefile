.PRECIOUS: %.ihx

all: LED_test.hex

%.hex: %.ihx
	packihx $< > $@

%.ihx: %.c
	sdcc -mmcs51 --code-size 2048 $< -o $@

clean:
	rm -rf *.ihx *.lk *.lst *.map *.mem *.rel *.rst *.sym *.asm