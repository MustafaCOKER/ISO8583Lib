CXX      := -c++
CXXFLAGS := -std=c++17 -fPIC
LDFLAGS  := -L/usr/lib -lstdc++ -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
LIB_DIR  := $(BUILD)/lib
TARGET   := libISO_8583.so
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.cpp)
OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

T_TARGET 	:= ISO8583Test.exe
T_BOOST_INC := -I/c/Source/boost_1_73_0/
T_BUILD     := ./tst_build
T_OBJ_DIR   := $(BUILD)/tst_objects
T_SRC       := $(wildcard test/*.cpp)
T_OBJECTS   := $(T_SRC:%.cpp=$(T_OBJ_DIR)/%.o)

all: mkdirs build build_test

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@ $(LDFLAGS)

$(T_OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) $(T_BOOST_INC) -c $< -o $@ $(LDFLAGS)

$(LIB_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(LIB_DIR)/$(TARGET) $^ $(LDFLAGS)

.PHONY: all build clean debug release mkdirs build_test

mkdirs:
	@mkdir -p $(LIB_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(T_OBJ_DIR)

build: $(OBJECTS)
	$(CXX) -shared $^ -o $(LIB_DIR)/$(TARGET)

build_test: $(T_OBJECTS) $(LIB_DIR)/$(TARGET)
	$(CXX) -o $(T_BUILD)/$(T_TARGET) $(T_OBJECTS) -L$(LIB_DIR)/$(TARGET)
	

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(T_OBJ_DIR)/*
	-@rm -rvf $(LIB_DIR)/*