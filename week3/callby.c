#include <stdio.h>
#include <stdlib.h>

typedef struct Adder {
    int a;
    int b;
    int result;
} Adder;

int p, q, r;

void sum_global();
void sum_callbyval(int, int);
int sum_retbyval(int, int);
void sum_callbyref(int *, int *, int *);
int *sum_retbyref(int*, int*);

Adder *createAdder(int a, int b);

int main() {
    int a=20, b=30, res;

    p = a;
    q = b;

    sum_global();
    printf("After sum_global(): %d + %d = %d\n", p, q, r);

    printf("Data transfer by call by val: a= %d, b = %d => ", a, b);
    sum_callbyval(a, b);

    res = sum_retbyval(a, b);
    printf("Data transfer by return by val: %d\n", res);

    sum_callbyref(&a, &b, &res);
    printf("Data transfer by call by ref: %d + %d = %d\n", a, b, res);

    res = *sum_retbyref(&a, &b);
    printf("Data transfer by return by ref: %d\n", res);

    Adder *adder = createAdder(a, b);
    printf("Data transfer by adder struct : %d + %d = %d\n", adder->a, adder->b, adder->result);
    free(adder);

    return 0;
}

void sum_global() {
    r = p + q;
}

void sum_callbyval(int a, int b) {
    int c = a + b; // ?
    printf("call by value : %d\n", c);
}

int sum_retbyval(int a, int b) {
    return a + b;
}

void sum_callbyref(int *a, int *b, int *c) {
    *c = *a + *b;
}

int *sum_retbyref(int *a, int *b) {
    int *c = malloc(sizeof(int));
    *c = *a + *b;
    return c;
}

Adder *createAdder(int a, int b) {
    Adder *adder = malloc(sizeof(Adder));
    adder->a = a;
    adder->b = b;
    adder->result = a+b;
    return adder;
}