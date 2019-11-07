CC = gcc
CFLAGS = -std=c99 -o
VALIDATION_FILES = validation.c errorPrinter.c
VALIDATION_EXEC = validationMain
DISPLAY_FILES = display.c errorPrinter.c
DISPLAY_EXEC = displayMain
DEPENDENCIES = validation.h display.h

build: build-valid build-display

build-display : $(DEPENDECIES)
	$(CC) $(DISPLAY_FILES) $(CFLAGS) $(DISPLAY_EXEC)
build-valid: $(DEPENDECIES)
	$(CC) $(VALIDATION_FILES) $(CFLAGS) $(VALIDATION_EXEC)