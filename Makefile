.PHONY: all build clean tests build_tests

OS=$(shell uname -s)
SHELL:=/bin/bash
ifeq ($(OS), Darwin)
	OPEN=open
else
	OPEN=xdg-open
endif

CC=g++
CXXFLAGS= -std=c++17 -Werror -Wall -Wextra -O0 -g
LDFLAGS=-lgtest -pthread
TESTSRC=tests.cc

LIBSRC=$(wildcard lib/*.cc)

SRCFILES=\

HDRFILES=\

SRCOBJ=$(SRCFILES:.cc=.o)
TESTOBJ=$(TESTSRC:.cc=.o)

LIB_ONE_FILES=\


LIB_ONE_OBJ=$(LIB_ONE_FILES:.cc=.o)
LIB_ONE=

EXECUTABLE=chess
EXECUTABLE_TEST=chess_test
REPORTDIR=.
LEAKS_REPORT_FILE=leaks_report.txt

# all: build

# build: clean $(SRCOBJ) libs
# 	$(CC) $(SRCOBJ) $(LIB_ONE) -o $(EXECUTABLE) $(LDFLAGS)


# libs: $(LIB_ONE)

# $(LIB_ONE): $(LIB_ONE_OBJ)
# 	ar rcs $@ $^
# 	ranlib $@


# %.o: %.cc
# 	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	@rm -f $(TESTOBJ) $(SRCOBJ) $(EXECUTABLE) $(EXECUTABLE_TEST) $(LIB_ONE) $(LIB_ONE_OBJ)

# test: clean $(TESTOBJ) libs
# 	$(CC) $(TESTOBJ) $(LIB_ONE) -g -o $(EXECUTABLE_TEST) $(LDFLAGS)
# 	./$(EXECUTABLE_TEST)

# dvi:
# 	$(OPEN) index.html

test:
	$(CC) $(CXXFLAGS) figures.cc board.cc test.cc -g -o $(EXECUTABLE_TEST) $(LDFLAGS) 
	./$(EXECUTABLE_TEST)

style:
	-@clang-format -i -style=file $(SRCFILES) $(HDRFILES) $(LIB_ONE_FILES) *.cc *.h

# cppcheck:
# 	cppcheck --language=c++ --std=c++17 --enable=all \
# 	--suppress=missingInclude $(SRCFILES) $(HDRFILES) $(LIB_ONE_FILES) main.cc

# leaks:
# 	valgrind --leak-check=full --verbose --log-file=$(REPORTDIR)/$(LEAKS_REPORT_FILE) ./$(EXECUTABLE_TEST)