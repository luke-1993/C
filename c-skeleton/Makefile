CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LDLIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

#list of .c files, by wildcard search
SOURCES=$(wildcard src/**/*.c src/*.c)
#list of .o files, using SOURCES file list, changing extension from .c to .o
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
#list of test files, using TEST_SRC file list, deleting .c extension
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/libex29.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
# if user doesn't specify a target, by default make runs the first target here
# the first target is all:, make will build TARGET library and tests
all: $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
		ar rcs $@ $(OBJECTS)

#notation says put the target for this makefile
#here and all the OBJECTS after that. $@ maps to
#$(TARGET) on line 19.
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)
# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`
# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# The Checker
BADFUNCS='[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byt
check:
	@echo Files with potentially dangerous functions.
	@egrep $(BADFUNCS) $(SOURCES) || true
