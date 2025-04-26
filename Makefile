# Makefile

# Compiler
CC = gcc

# Source and Build directories
SRC_DIR = .
BUILD_DIR = build

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files (executables)
EXES = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRCS))

# Default target
all: $(BUILD_DIR) $(EXES)

# Rule to build executables
$(BUILD_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
