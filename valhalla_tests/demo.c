#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int fishy(void){
    int *block;

    int neg_size = -2;
    block = malloc(neg_size);
    free(block);
}

int invalid_free(void){

    int *b = malloc(2*sizeof(int));
    int random_var;
    // free after block
    free(b+2);
    // free inside block
    free(b+1);
    // free before block
    free(b-1);

    b = realloc(b, 3);
    // free inside block
    free(b+1);

    // double free
    free(b);
    free(b);

    free(&random_var);
    return 0;
}

int invalid_rw(void){

    int *b = malloc(1*sizeof(int));
    b[1] = 1;
    int i = 0;
    b[3] = 2; 
    for (; i < 5; i++){
        b[3]++; 
    }
    
    free(b);
}

typedef struct _node {
    struct _node* indir;
} node;

int memleak(void){
    node *indir_lost = malloc(sizeof(node));
    indir_lost->indir = malloc(sizeof(node));
    free(indir_lost);

    node *dir_lost = malloc(sizeof(node));
    dir_lost = NULL;

    node *dir_reach = malloc(sizeof(node));
    dir_reach->indir = malloc(sizeof(node));

    return 0;
}

int overlap(void){

    char copy_fwd[10] = "hello";
    memcpy(copy_fwd, copy_fwd+1, 6);

    char copy_bwd[10] = "hello";
    memcpy(copy_bwd+3, copy_bwd, 4);

    return 0;
}

int main(void){
    fishy();
    invalid_free();
    invalid_rw();
    memleak();
    overlap();
}

