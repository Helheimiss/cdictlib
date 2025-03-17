CC = gcc
target = cdictlib
src = src/main.c src/cdictlib.c
bin = bin/release/
flags = -Wall -o $(bin)$(target).exe

$(shell mkdir -p bin/release)

all :
	$(CC) $(src) $(flags)


clear :
	rm -f $(bin)*.exe