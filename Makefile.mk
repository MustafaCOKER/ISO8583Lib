CXX      := -g++
CXXFLAGS := -std=c++17 -fPIC
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
BIN_DIR  := $(BUILD)/bin
INCLUDE  := -I../include/
SRC      := $(wildcard *.cpp)
OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all build clean makedirs

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

all: makedirs build

makedirs:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)
	
clean:
	-@rm -rvf $(BIN_DIR)/*
	-@rm -rvf $(OBJ_DIR)/*