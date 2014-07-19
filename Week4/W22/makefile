CC=gcc
CFLAGS = -Wall -std=c99

W_DEPS = LinkedListDeque.h Bag.h
W_OBJ = W22.o Bag.o LinkedListDeque.o

%.o: %.c $(W_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

W22.mgd: $(W_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


