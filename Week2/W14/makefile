CC=gcc
CFLAGS = -Wall -std=c99

W14_DEPS = DynArr.h
W14_OBJ = W14.o DynArr.o

%.o: %.c $(W14_DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

W14.mgd: $(W14_OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

