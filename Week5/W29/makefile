CC=gcc
CFLAGS = -Wall -std=c99

W_DEPS = BST.h
W_OBJ = W29.o BST.o

%.o: %.c $(W_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

W29.mgd: $(W_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


