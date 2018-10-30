#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    int *mem_addr;
    int ref_addr, ref_value;
    // conditional depends on uninit'd value (stack)
    int a;
    if (a > 0) a = 1;
    
    // conditional depends on uninit'd value (heap)
    int *b = malloc(sizeof(int));
    if (*b > 0) *b = 1;
    free(b);
    
    // conditional used in syscall (stack)
    int c;
    printf("Uninitialized: %d", c);

    // conditional used in syscall (heap)
    int *d = malloc(sizeof(int));
    printf("Uninitialized: %d", *d);
    free(d);

    // conditional used in dereference (stack)
    int e;
    // using % 100 prevents illegal access errors
    mem_addr = &ref_addr + e%100;
    ref_value += *mem_addr;

    // conditional used in dereference (heap)
    int *f = malloc(sizeof(int));
    mem_addr = &ref_addr + (*f)%100; 
    ref_value += *mem_addr;
    free(f);
}
