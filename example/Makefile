include ../Makefile.mk

TARGET   	:= libISO_8583Example.exe
LIB_ISO8583 := ../src/build/bin/libISO_8583.so

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	$(CXX) -o $(BIN_DIR)/$(TARGET) $^ $(LIB_ISO8583)

build: $(BIN_DIR)/$(TARGET)