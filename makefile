CC = gcc
ARCH = 64
target = cdictlib
src = src/main.c src/cdictlib.c
bin = bin/
flags = -Wall -m$(ARCH) -s -o $(bin)release/$(target).exe

$(shell mkdir -p $(bin)release)

all :
	$(CC) $(src) $(flags)


clean :
	rm -f $(bin)release/*.exe
	rm -f $(bin)debug/*.exe