#include <stdlib.h>
#include <unistd.h>

#define STDOUT 1

// modified from valgrind mc manual, 4.2.3
int main(void){
    // syscall points to uninit'd bytes (stack)
    char stack_arr[10];
    write(STDOUT, stack_arr, 10);
    
    // syscall points to uninit'd bytes (heap)
    char* heap_arr  = malloc(10);
    write(STDOUT, heap_arr, 10);
    free(heap_arr);

    // write contains uninit'd bytes
    int* arr2 = malloc(sizeof(int));
    exit(arr2[0]);
}
