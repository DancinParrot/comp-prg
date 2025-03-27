COMPILER = g++
OPTIONS = -std=c++11 -O2 -Wall -pedantic -Wconversion -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address
COMPILE=$(COMPILER) $(OPTIONS)

BUILD=build2
SRC := abc051_b.cpp
BF := abc051_b_bf.cpp
TEST := $(wildcard tests/*.cpp)

.PHONY: all clean

all: main bruteforce test

main: $(SRC) 
	$(COMPILE) $(SRC) -o $(BUILD)/$@

bruteforce: $(BF) 
	$(COMPILE) $(BF) -o $(BUILD)/$@

test: $(TEST)
	$(COMPILE) $(TEST) -o $(BUILD)/gen

clean:
	rm -rf $(OBJS) $(DEPS) $(PRGM)
