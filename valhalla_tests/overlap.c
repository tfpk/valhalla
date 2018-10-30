#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

    char copy_fwd[10] = "hello";
    memcpy(copy_fwd, copy_fwd+1, 6);

    char copy_bwd[10] = "hello";
    memcpy(copy_bwd+3, copy_bwd, 4);

    return 0;
}
