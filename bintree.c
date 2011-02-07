#include "bintree.h"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

void insert(tnode_t **tree, int data)
{
    assert(tree != NULL);

    if (*tree == NULL) {
        *tree = malloc(sizeof(tnode_t));
        if (tree == NULL) {
            fprintf(stderr, "malloc: cannot allocate memory\n");
            exit(ENOMEM);
        }
        (*tree)->data = data;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
    }
    else {
        if (data <= (*tree)->data) {
            insert(&(*tree)->lchild, data);
        }
        else {
            insert(&(*tree)->rchild, data);
        }
    }
}

void print_inorder(tnode_t *tree)
{
    if (tree == NULL)
        return;

    print_inorder(tree->lchild);
    printf("%d\n", tree->data);
    print_inorder(tree->rchild);
}

int size(tnode_t *tree)
{
    if (tree == NULL)
        return 0;

    return size(tree->lchild) + size(tree->rchild) + 1;
}

int _to_array(tnode_t *tree, int *arr, int i)
{
    if (tree->lchild != NULL)
        i = _to_array(tree->lchild, arr, i);

    arr[i++] = tree->data;

    if (tree->rchild != NULL)
        i = _to_array(tree->rchild, arr, i) + 1;

    return i;
}

int *to_array(tnode_t *tree)
{
    if (tree == NULL)
        return NULL;

    int *arr = malloc(sizeof(tnode_t) * size(tree));
    if (arr == NULL) {
        fprintf(stderr, "malloc: cannot allocate memory\n");
        exit(ENOMEM);
    }

    _to_array(tree, arr, 0);

    return arr;
}

void insert2(tnode_t2 **tree, void *data, int (*comp)(void *, void *))
{
    assert(tree != NULL);

    if (*tree == NULL) {
        *tree = malloc(sizeof(tnode_t2));
        if (tree == NULL) {
            fprintf(stderr, "malloc: cannot allocate memory\n");
            exit(ENOMEM);
        }
        (*tree)->data = data;
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
    }
    else {
        if (comp(data, (*tree)->data) <= 0) {
            insert2(&(*tree)->lchild, data, comp);
        }
        else {
            insert2(&(*tree)->rchild, data, comp);
        }
    }
}
