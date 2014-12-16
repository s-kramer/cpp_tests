CC=ccache clang++
CFLAGS=-c -Wall -std=c++14 -g -O0
LDFLAGS=-lboost_system -lboost_unit_test_framework
SOURCES=fibonacci.cpp fibonacci_unittest.cpp fibonacci_main_cached.cpp fibonacci_main_recalc.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fibonacci

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	./$(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) *.o

main_cached: $(OBJECTS)
	$(CC) $(LDFLAGS) fibonacci_main_cached.o fibonacci.o -o $@

main_recalc: $(OBJECTS)
	$(CC) $(LDFLAGS) fibonacci_main_recalc.o fibonacci.o -o $@
