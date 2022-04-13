#Main application file name
MAIN_APP = ledBlink
#Main hex file path in windows format
MAIN_HEX_PATH = $(CURDIR)\$(MAIN_APP).hex

# Compiler and other Section
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE := avrdude

#Options for avr-gcc
CFLAGS = -g -Os -o

#Linking options for avr-gcc
LFLAGS = -Os -mmcu=atmega328p -o

#Options for HEX file generation
HFLAGS = -j .text -j .data -O ihex

#Options for avrdude to burn the hex file
#MMCU model here according to avrdude options
DUDEFLAGS = -p
DUDEFLAGS += m328p
DUDEFLAGS += -c
DUDEFLAGS += arduino 
DUDEFLAGS += -P 
DUDEFLAGS += COM3 
# DUDEFLAGS += -b 
# DUDEFLAGS += 9600 
DUDEFLAGS += -U flash:w:$(MAIN_HEX_PATH):i

# Sources files needed for building the application 
SRC = $(MAIN_APP).c

# The headers files needed for building the application (if you have own library you add them)
INCLUDE = -I. 
INCLUDE += 

# commands Section
Burn : Build
	$(AVRDUDE) $(DUDEFLAGS)

Build : $(MAIN_APP).elf
	$(OBJCOPY) $(HFLAGS) $< $(MAIN_APP).hex
	
$(MAIN_APP).elf: $(MAIN_APP).o
	$(CC) $(SRC) $(INCLUDE) $(LFLAGS) $@
	
$(MAIN_APP).o:$(SRC)
	$(CC) $^ $(INCLUDE) $(CFLAGS) $@