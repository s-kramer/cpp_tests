CC=ccache clang++
CFLAGS=-c -Wall -std=c++14 -g -pg
LDFLAGS=-lboost_system -lboost_unit_test_framework -pg
SOURCES=fibonacci.cpp fibonacci_unittest.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fibonacci

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	./$(EXECUTABLE)

profile: fibonacci_profiled.o fibonacci.o
	$(CC) $(LDFLAGS) fibonacci_profiled.o fibonacci.o -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
