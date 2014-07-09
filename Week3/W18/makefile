CC=gcc
CFLAGS = -Wall -std=c99

W_DEPS = LinkedListQueue.h
W_OBJ = W18.o LinkedListQueue.o

%.o: %.c $(W_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

W18.mgd: $(W_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


