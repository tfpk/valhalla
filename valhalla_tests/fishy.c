#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    int *block;

    int neg_size = -2;
    block = malloc(neg_size);
    free(block);
}
