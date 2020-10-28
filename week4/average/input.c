#include <stdio.h>
#include <stdlib.h>

extern int count;
int total = 0;

int input_data() {
    int i, *buf;
    printf("input size: ");
    scanf("%d", &count);

    buf = malloc(sizeof(int) * count);

    for (i=0;i<count;i++) {
        printf("input number (%d/%d): ", (i+1), count);
        scanf("%d", buf+i);
        total += buf[i];
    }

    return total;
}

// --allow-shlib-undefined  >>  -undefined dynamic_lookup
// gcc -shared -fPIC -o libavg.so -undefined dynamic_lookup average.c input.c