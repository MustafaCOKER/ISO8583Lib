include ../Makefile.mk

TARGET   := libISO_8583.so

$(BIN_DIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/$(TARGET) $^ $(LDFLAGS)

build: $(OBJECTS)
	$(CXX) -shared $^ -o $(BIN_DIR)/$(TARGET)