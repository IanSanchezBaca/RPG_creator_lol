# Makefile

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++17 -Wall -Wextra -std=c++11
DEBUGFLAGS = -g

# Linker flags for SDL2
LDFLAGS = -lSDL2 -lSDL2_image

# Source files
SRCS = main.cpp game.cpp TextureManager.cpp Map.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = rpg_creator

# Main target
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJS) -o $(EXEC) $(LDFLAGS)

# Compile source files to object files
%.o: %.cpp
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o  $@

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC) 
