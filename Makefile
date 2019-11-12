## MACROS 
## CC - C Compiler (gcc)
## CFLAGS - flags/arguemnts for gcc (std=c99 for newer standard, -o to specify outout name)
## VALIDATION_FILES - validationMain source code files
## VALIDATION_EXEC - final name for the validation executable 
## DISPLAY_FILES - displayMain source code files
## DISPLAY_EXEC - file name for display executable
## DEPENDENCIES - files required to be present for compilation. 

CC = gcc
CFLAGS = -std=c99 -o
VALIDATION_FILES = validation.c errorPrinter.c
VALIDATION_EXEC = validationMain
DISPLAY_FILES = display.c errorPrinter.c
DISPLAY_EXEC = displayMain
DEPENDENCIES = validation.h display.h

##RUTINES
##build - cleans and builds both display and validation 
##build-display - builds display
##build-validation - builds validation
##clean - clean older execution files. 

build: clean build-valid build-display

build-display : $(DEPENDENCIES)
	$(CC) $(DISPLAY_FILES) $(CFLAGS) $(DISPLAY_EXEC)
build-valid: $(DEPENDENCIES)
	$(CC) $(VALIDATION_FILES) $(CFLAGS) $(VALIDATION_EXEC)
clean:
	rm -f $(DISPLAY_EXEC) $(VALIDATION_EXEC) 
