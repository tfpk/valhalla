#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

    int *b = malloc(1*sizeof(int));
    b[1] = 1;
    int i = 0;
    b[3] = 2; 
    for (; i < 5; i++){
        b[3]++; 
    }
    
    free(b);
}
