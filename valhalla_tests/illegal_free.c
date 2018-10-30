#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

    int *b = malloc(2*sizeof(int));
    // free after block
    free(b+2);
    // free inside block
    free(b+1);
    // fre before block
    free(b-1);

    // double free
    free(b);
    free(b);
    return 0;
}
