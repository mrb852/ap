#compiler flags
CXX =g++
CPPFLAGS+=-Wall -std=c++11

#debugging
CPPFLAGS +=-g

#Optimization level
CPPFLAGS +=-O3

PROJECT_NAME=program
SOURCES=$(shell find . -type f -iname '*.cpp')
OBJECTS = $(SOURCES:.cpp=.o)
BIN_DIR = bin/
SRC_DIR = src/
EXECUTABLE = $(PROJECT_NAME)

.PHONY: default clean all executable

default: all

run: $(EXECUTABLE)
	@$(BIN_DIR)$(PROJECT_NAME)

clean:
	@rm -rf $(BIN_DIR)
	rm -f $(OBJECTS)

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BIN_DIR);
	@$(CXX) $(CPPFLAGS) -o $(BIN_DIR)$(EXECUTABLE) $(OBJECTS) $(LIBS) $(LDFLAGS);

all: clean $(EXECUTABLE)
