CC_LINUX = g++
CC = clang++

#Where hpp file is saved
DIR_INCLUDE = /usr/local/include

#Where lib is saved
DIR_LIB = /usr/local/lib/

#Archive file name
ARCHIVE_FILE = libgstd.a

#Header files (for uninstalling process)

all: gstd.cpp
	$(CC) -o libgstd.a -c gstd.cpp

all_linux: gstd.cpp
	$(CC_LINUX) -o libstd.a -c gstd.cpp

install: all
	cp *.hpp $(DIR_INCLUDE)
	cp $(ARCHIVE_FILE) $(DIR_LIB)

install_linux: all_linux
	cp *.hpp $(DIR_INCLUDE)
	cp $(ARCHIVE_FILE) $(DIR_LIB)  
