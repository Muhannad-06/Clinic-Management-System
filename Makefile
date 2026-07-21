# Makefile for Clinic-Management-System
#
# The code was originally written against <windows.h> (for Sleep()), so the
# "native" way to build it is with a Windows compiler or a MinGW cross
# compiler. APP/Clinic.c now has a small portability shim (#ifdef _WIN32)
# so it also builds with plain gcc/clang on Linux/macOS for development
# and testing; on those platforms Sleep() is mapped to usleep().
#
# Usage:
#   make            # build with the host compiler (gcc/clang) -> bin/clinic
#   make windows    # cross-compile a Windows .exe with MinGW  -> bin/clinic.exe
#   make run        # build (if needed) and run
#   make clean      # remove build artifacts

CC       := gcc
MINGW_CC := x86_64-w64-mingw32-gcc

CFLAGS   := -std=c11 -Wall -Wextra -g
SRC_DIRS := APP ADMIN USER
BUILD_DIR := build
BIN_DIR   := bin

SRCS := APP/Clinic.c APP/Models.c ADMIN/Admin_Program.c USER/User_Program.c
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

TARGET      := $(BIN_DIR)/clinic
WIN_TARGET  := $(BIN_DIR)/clinic.exe

.PHONY: all windows run clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

windows: $(SRCS) | $(BIN_DIR)
	$(MINGW_CC) $(CFLAGS) $(SRCS) -o $(WIN_TARGET)

run: $(TARGET)
	./$(TARGET)

$(BUILD_DIR) $(BIN_DIR):
	@mkdir -p $@

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
