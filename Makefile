COMPILER = g++
OPTIONS = -std=c++11 -O2 -Wall -pedantic -Wconversion -Wshift-overflow=2 -Wduplicated-cond -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address

COMPILE=$(COMPILER) $(OPTIONS)
BUILD=build
SRC ?= main.cpp
BF := main_bf.cpp
TEST := $(wildcard tests/*.cpp)

.PHONY: all clean

all: main bruteforce test

# make main SRC=/path/to/file
main: $(SRC) 
	$(COMPILE) $(SRC) -o $(BUILD)/$@

bruteforce: $(BF) 
	$(COMPILE) $(BF) -o $(BUILD)/$@

test: $(TEST)
	$(COMPILE) $(TEST) -o $(BUILD)/gen

clean:
	rm -rf $(OBJS) $(DEPS) $(PRGM)
