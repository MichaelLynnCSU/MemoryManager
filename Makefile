# List of files
SRC     = MemoryManager.c Driver.c	
OBJS    = MemoryManager.o   Driver.o	
HEADERS =          MemoryManager.h		

EXE		= PA1	

# Compiler and loader commands and flags
# -pthread -funroll-loops -funit-at-a-time -fbranch-target-load-optimize
CC	= gcc
CC_FLAGS  = -Wall -O3 --std=c++14 -c -g -o

# The first, and hence default, target is the executable
$(EXE): $(OBJS)
	$(CC)  $(OBJS) -o $(EXE)

# Compile .cpp files to .o files
%.o : %.cpp
	$(CC) $(CC_FLAGS) $@ $<

# Clean up the directory
clean:
	rm -f $(OBJS) $(EXE) $(EXE).tar

# Package the directory
package:
	tar -cvf $(EXE).tar $(SRC) $(HEADERS) Makefile
