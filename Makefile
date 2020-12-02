# The compiler to use
CC=g++

# Compiler flags
CFLAGS=-c -Wall
    # -c: Compile or assemble the source files, but do not link.
    # The linking stage simply is not done.
    # The ultimate output is in the form of an object file
    # for each source file.
    #
    # -Wall: This enables all the warnings about constructions that
    # some users consider questionable, and that are easy to avoid
    # (or modify to prevent the warning), even in conjunction with macros.

# Name of executable output
EXECUTABLE=pacman

all: $(EXECUTABLE)

# The executable depends on all the separate object files
$(EXECUTABLE): main.o apple.o controller.o
	$(CC) main.o apple.o controller.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

apple.o: apple.cpp
	$(CC) $(CFLAGS) apple.cpp

controller.o: controller.cpp
	$(CC) $(CFLAGS) controller.cpp

clean:
	rm -f *.o $(EXECUTABLE)