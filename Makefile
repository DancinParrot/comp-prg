COMPILER = g++
OPTIONS = -Wall -Wextra -pedantic -std=c++11 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector

COMPILE=$(COMPILER) $(OPTIONS)
BUILD=build
SRC ?= main.cpp
TEST := $(wildcard tests/*.cpp)

.PHONY: all clean

all: main bruteforce test

# To run: make main SRC=/path/to/file, otherwise specify in this file
main: $(SRC) 
	$(COMPILE) $(SRC) -o $(BUILD)/$@

test: $(TEST)
	$(COMPILE) $(TEST) -o $(BUILD)/gen

# To run: make 2000C will build 2000C.cpp
% : %.cpp
	$(COMPILE) $< -o $(BUILD)/$@

clean:
	rm -rfv $(OBJS) $(DEPS) $(PRGM) $(TEST)/* $(BUILD)/*
