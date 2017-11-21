CFLAGS=-Wall -g -Wextra -std=gnu99

SOURCES = $(wildcard src/**/*.c src/*.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

TARGET = logfind
BUILD_TARGET = build/liblogfind.a
SO_TARGET = $(patsubst %.a, %.so, $(TARGET))

all : $(TARGET)

$(TARGET): build src/$(TARGET).c
	$(CC) $(CFLAGS) -o build/$(TARGET) src/$(TARGET).c



build:
	@mkdir -p build

clean :
	rm -rf build $(OBJECTS)
	find . -name "*.gc*" -exec rm {} \;
