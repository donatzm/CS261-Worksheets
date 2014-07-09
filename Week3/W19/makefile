CC=gcc
CFLAGS = -Wall -std=c99

W_DEPS = LinkedListDeque.h
W_OBJ = W19.o LinkedListDeque.o

%.o: %.c $(W_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

W19.mgd: $(W_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


