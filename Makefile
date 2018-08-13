CC=g++
CFLAGS=-Wall -std=c++11 -O3
OBJECTS=main.o \
		models/word.o
TARGET=run
## DIRS
SRC_DIR=src
BUILD_DIR=build
BIN_DIR=bin
SUCCESS_MSG=Successfully build the project

all: $(BIN_DIR)/$(TARGET) done

$(BIN_DIR)/$(TARGET): $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(OBJECTS)) $(BIN_DIR)
	$(CC) $(addprefix $(BUILD_DIR)/,$(OBJECTS)) $(CFLAGS) -o $(BIN_DIR)/$(TARGET)
	@echo

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $< $(CFLAGS) -c -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR) && find ./$(SRC_DIR)/. -type d | sed -e "s/$(SRC_DIR)/$(BUILD_DIR)/" | xargs mkdir -p

$(BIN_DIR):
	mkdir $(BIN_DIR)

done:
	@echo $(SUCCESS_MSG)

clean:
	rm -rf $(BIN_DIR) $(BUILD_DIR)
