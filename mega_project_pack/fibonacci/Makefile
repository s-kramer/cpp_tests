CC=ccache clang++
CFLAGS=-c -Wall -std=c++14 -g -O0
LDFLAGS=-lboost_system -lboost_unit_test_framework

GPROF?=no

ifeq ($(GPROF),yes)
	LDFLAGS+=-pg
endif

SOURCES=fibonacci.cpp fibonacci_unittest.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fibonacci

all: $(SOURCES) $(EXECUTABLE)  fibonacci_cached_prof fibonacci_recalc_prof
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	./$(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) *.o fibonacci_cached_prof fibonacci_recalc_prof

fibonacci_cached_prof: $(OBJECTS) fibonacci_cached_prof.o
	$(CC) $(LDFLAGS) fibonacci_cached_prof.o fibonacci.o -o $@

fibonacci_recalc_prof: $(OBJECTS) fibonacci_recalc_prof.o
	$(CC) $(LDFLAGS) fibonacci_recalc_prof.o fibonacci.o -o $@
