#include "bintree.h"
#include "dlist.h"

#include <stdio.h>
#include <string.h>

// Helper function for testing insert2
int mystrcmp(void *a, void *b)
{
    return strcmp((const char*) a, (const char*) b);
}

int main()
{
    // Opgave 1:
    tnode_t *tree = NULL;
    insert(&tree, 5);
    printf("Data: %d\n", tree->data);

    insert(&tree, 2);
    insert(&tree, 8);
    printf("Left: %d\n", tree->lchild->data);
    printf("Right: %d\n", tree->rchild->data);

    print_inorder(tree);

    int s = size(tree);
    printf("Size: %d\n", s);

    int *arr = to_array(tree);
    for (int i = 0; i < s; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Opgave 2:
    dlist_t *current = tree2dlist(tree);
    for (int i = 0; i < s; ++i) {
        printf("%d\n", current->data);
        current = current->next;
    }

    current = tree2dlist(tree);
    for (int i = 0; i < s; ++i) {
        printf("%d\n", current->data);
        current = current->prev;
    }

    // Opgave 3:
    tnode_t2 *tree2 = NULL;
    insert2(&tree2, "foo", mystrcmp);
    insert2(&tree2, "bar", mystrcmp);
    insert2(&tree2, "zzz", mystrcmp);
    printf("Root: %s\nLeft: %s\nRight: %s\n",
        (char*)tree2->data,
        (char*)tree2->lchild->data,
        (char*)tree2->rchild->data
    );

    return 0;
}
