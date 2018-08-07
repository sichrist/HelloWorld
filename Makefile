
CC=g++

CFLAGS=-Wall -pedantic -Werror -g -DVERSION=\"$(GIT_VERSION)\"
SRC:=$(wildcard src/*.cpp)
OBJS = $(SRC:src/%.cpp=src/%.o)
all:
	echo $(SRC)
	echo $(OBJS)

HelloWorld: $(SRC)
	$(CC) $(CFLAGS) $^ -o HelloWorld

