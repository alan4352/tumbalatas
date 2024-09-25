
BOARD_TAG = arduino:avr:uno
PORT = /dev/ttyUSB0
CORE = arduino:avr
FQBN = $(BOARD_TAG)
TARGET = Tumbalatas

# Actions
compile:
	arduino-cli compile --fqbn $(FQBN) $(TARGET).ino

upload: compile
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(TARGET).ino

clean:
	rm -rf *.hex
