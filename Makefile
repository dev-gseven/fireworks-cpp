TARGET = fireworks-cpp

# Detects OS
OS := $(shell uname 2>/dev/null || echo Windows)

# Choose compiler depending on the system
ifeq ($(OS), Windows)
	CXX = g++.exe
	RM = del /F /Q
else
	CXX = g++
	RM = rm -f
endif

ifeq ($(OS), Darwin)
	CXXFLAGS = -std=c++17 -pthread
else
	CXXFLAGS = -std=c++17 -pthread -static
endif


SRC = fireworks-cpp.cpp

# Compiling
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# if you want to remove
clean:
	$(RM) $(TARGET)

# Define "clean" as special to avoid conflicts
.PHONY: clean
