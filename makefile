OS := $(shell uname)
ifeq ($(OS),Darwin)
	CC = clang++ -std=c++11
else
	CC = g++ -std=c++11
endif

#Where hpp file is saved
DIR_INCLUDE = /usr/local/include/gstd

#Where lib is saved
DIR_LIB = /usr/local/lib/

#Archive file name
ARCHIVE_FILE = libgstd.a

#Header files (for uninstalling process)

all: gstd.cpp
	$(CC) -o libgstd.a -c gstd.cpp

install: all
	mkdir -p $(DIR_INCLUDE)
	mkdir -p $(DIR_LIB)
	cp *.hpp $(DIR_INCLUDE)
	cp $(ARCHIVE_FILE) $(DIR_LIB)
