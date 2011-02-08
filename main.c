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
    printf("Tester insert...\n");
    tnode_t *tree = NULL;
    insert(&tree, 5);
    printf("Data: %d\n", tree->data);

    insert(&tree, 2);
    insert(&tree, 8);
    printf("Left: %d\n", tree->lchild->data);
    printf("Right: %d\n", tree->rchild->data);

    printf("\nTester print_indorder\n");
    print_inorder(tree);

    printf("\nTester size\n");
    int s = size(tree);
    printf("Size: %d\n", s);

    printf("\nTester to_array\n");
    insert(&tree, 10);
    insert(&tree, 7);
    insert(&tree, 80);
    insert(&tree, 1);
    insert(&tree, 4);
    insert(&tree, 3);
    s = size(tree);
    printf("Size: %d\n", s);
    print_inorder(tree);
    int *arr = to_array(tree);
    for (int i = 0; i < s; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // Opgave 2:
    printf("\nTester tree2dlist\n");
    dlist_t *current = tree2dlist(tree);
    for (int i = 0; i < s; ++i) {
        printf("%d\n", current->data);
        current = current->next;
    }

    printf("\n");

    current = tree2dlist(tree);
    for (int i = 0; i < s; ++i) {
        printf("%d\n", current->data);
        current = current->prev;
    }

    // Opgave 3:
    printf("\nTester insert2\n");
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
