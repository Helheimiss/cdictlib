CC = gcc
target = main
src = src/main.c src/hashlist.c
bin = bin/
flags = -Wall -o $(bin)$(target).exe

$(shell mkdir -p bin)

all :
	$(CC) $(src) $(flags)


clear :
	rm -f $(bin)*.exe