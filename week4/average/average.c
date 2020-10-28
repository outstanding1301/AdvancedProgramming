#include <stdio.h>

extern int count;
extern int total;

double average() {
    return (double) total / count;
}