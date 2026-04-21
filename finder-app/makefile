# Compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Wextra -g

# Target application
TARGET := writer

# Source files
SRCS := writer.c
OBJS := $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Build the application
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(TARGET) *.o
