# Compiler
CC = g++
# Compiler flags
CFLAGS = -std=c++11 -Wall

# Source files
SRCS = system.cpp Customer.cpp Account.cpp Transaction.cpp Bank.cpp User.cpp Manager.cpp Employee.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = system

# Default target
all: $(EXEC)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@

# Clean the generated files
clean:
	rm -f $(OBJS) $(EXEC)
