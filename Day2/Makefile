# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Target executable name
TARGET = day2.exe

# Source file
SRC = day2.cpp

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	del /Q $(TARGET)

# Run the program
run: $(TARGET)
	.\$(TARGET)
