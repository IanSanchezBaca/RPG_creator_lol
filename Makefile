# Makefile

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++11

# Linker flags for SDL2
LDFLAGS = -lSDL2

# Source files
SRCS = main.cpp game.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = rpg_creator

# Main target
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC)
