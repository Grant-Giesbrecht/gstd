CC = clang++

all: gstd.cpp
	$(CC) -o libgstd.a -c gstd.cpp

