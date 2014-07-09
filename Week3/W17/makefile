CC=gcc
CFLAGS = -Wall -std=c99

W_DEPS = LinkedList.h
W_OBJ = W17.o LinkedList.o

%.o: %.c $(W_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

W17.mgd: $(W_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


