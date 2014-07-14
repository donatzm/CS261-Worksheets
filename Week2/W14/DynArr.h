#ifndef DynArr
#define DynArr

#define TYPE int
#define EQ(a, b) (a == b)

struct DynArray {
    TYPE *data;
    int size;
    int capacity;
};

void _initDynArray(struct DynArray * v, int capacity);
struct DynArray * createDynArr(int cap);

#endif