#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_ANIMALS 5
#define MAX_NAME_LEN 20

int main() {
    char **animals = NULL;
    int i;
    animals = malloc(NUM_OF_ANIMALS * sizeof(char*));
    for (i=0;i<NUM_OF_ANIMALS;i++) {
        animals[i] = malloc(MAX_NAME_LEN * sizeof(char));
        scanf("%s", &animals[i][0]);
    }
    for (i=0;i<NUM_OF_ANIMALS;i++) {
        if(i==NUM_OF_ANIMALS-1)
            printf("%s\n", animals[i]);
        else 
            printf("%s, ", animals[i]);
    }
    return 0;
}