CC = gcc
ARCH = 64
TARGET = cdictlibX$(ARCH)
OUT = $(TARGET).o
SRC = src/cdictlib.c
RELEASE_DEBUG = release
BIN = bin/$(RELEASE_DEBUG)



$(shell mkdir -p $(BIN))


dynamic :
	$(CC) -s -m$(ARCH) -shared -o $(BIN)/$(TARGET).dll $(SRC)


static : $(OUT)
	ar rcs $(BIN)/$(TARGET).a $(BIN)/$(OUT)

$(OUT) : $(SRC)
	$(CC) -s -m$(ARCH) -c $(SRC) -o $(BIN)/$(OUT)


clean :
	rm -f $(BIN)/*