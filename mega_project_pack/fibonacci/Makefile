CC=ccache clang++
CFLAGS=-c -Wall -std=c++14 -g -O0
LDFLAGS=

GPROF?=no

ifeq ($(GPROF),yes)
	LDFLAGS+=-pg
endif

SOURCES=fibonacci.cpp fibonacci_unittest.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=fibonacci

# Add boost dependency only to the actual tests
$(EXECUTABLE): LDFLAGS+=-lboost_system -lboost_unit_test_framework

all: $(SOURCES) $(EXECUTABLE)  fibonacci_cached_prof fibonacci_recalc_prof
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	./$(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) *.o fibonacci_cached_prof fibonacci_recalc_prof callgrind* gmon* fibonacci_profile_*

fibonacci_cached_prof: fibonacci.o fibonacci_cached_prof.o
	$(CC) $(LDFLAGS) $^ -o $@
ifeq ($(GPROF),yes)
	./$@
	mv gmon.out gmon.cached
	gprof $@ gmon.cached > ./fibonacci_profile_cached
else
	valgrind --tool=callgrind ./$@
	mv ./callgrind.out.* callgrind.prof.cached
endif

fibonacci_recalc_prof: fibonacci.o fibonacci_recalc_prof.o
	$(CC) $(LDFLAGS) $^ -o $@
ifeq ($(GPROF),yes)
	./$@
	mv gmon.out gmon.recalc
	gprof $@ gmon.recalc > ./fibonacci_profile_recalc
else
	valgrind --tool=callgrind ./$@
	mv ./callgrind.out.* callgrind.prof.recalc
endif
