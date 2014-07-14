CC=gcc
CFLAGS = -Wall -std=c99

W0_DEPS = ArrayBagStack.h
W0_OBJ = W0.o ArrayBagStack.o

%.o: %.c $(W0_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

W0.mgd: $(W0_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

