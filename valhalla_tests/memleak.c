#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct _node {
    struct _node* indir;
} node;

int main(void){
    node *indir_lost = malloc(sizeof(node));
    indir_lost->indir = malloc(sizeof(node));
    free(indir_lost);

    node *dir_lost = malloc(sizeof(node));
    dir_lost = NULL;

    node *dir_reach = malloc(sizeof(node));
    dir_reach->indir = malloc(sizeof(node));

    return 0;
}
