# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Valgrind flags
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all

# Executable names
EXEC = main
TEST_EXEC = test

# Source files
SRCS = main.cpp Graph.cpp 
TEST_SRCS = Test.cpp Graph.cpp

# Header files
HEADERS = Graph.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# Default rule
all: $(EXEC) $(TEST_EXEC)

# Rule to link the main executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

# Rule to link the test executable
$(TEST_EXEC): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJS)

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to run Valgrind on the main executable
valgrind: $(EXEC)
	valgrind $(VALGRIND_FLAGS) ./$(EXEC)

# Rule to run Valgrind on the test executable
valgrind-test: $(TEST_EXEC)
	valgrind $(VALGRIND_FLAGS) ./$(TEST_EXEC)


# Rule to run clang-tidy on each source file separately
tidy:
	clang-tidy $(SRCS) $(HEADERS) -- $(CXXFLAGS)


# Rule to clean the directory
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(EXEC) $(TEST_EXEC)

# Phony targets
.PHONY: all clean valgrind valgrind-test tidy
