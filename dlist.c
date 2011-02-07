#include "dlist.h"

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

dlist_t *tree2dlist(tnode_t *tree)
{
    if (tree == NULL)
        return NULL;

    // Convert tree to array and get its size:
    int arrsize = size(tree);
    int *arr = to_array(tree);

    // Allocate head element of the list:
    dlist_t *head = malloc(sizeof(dlist_t));
    if (head == NULL) {
        fprintf(stderr, "malloc: cannot allocate memory\n");
        exit(ENOMEM);
    }
    head->data = arr[0];
    head->prev = head;
    head->next = head;

    // Iterate through the elements in the tree/array:
    for (int i = 1; i < arrsize; ++i) {
        dlist_t *current = malloc(sizeof(dlist_t));
        if (current == NULL) {
            fprintf(stderr, "malloc: cannot allocate memory\n");
            exit(ENOMEM);
        }

        // Update previous and current element.
        // Loop invariant: the previous element of the head is the
        //                 last inserted element in the list
        current->data = arr[i];
        current->next = head;
        current->prev = head->prev;
        head->prev->next = current;
        head->prev = current;
    }

    return head;
}
