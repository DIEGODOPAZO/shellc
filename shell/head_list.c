//
// Created by marcos on 11/18/22.
//

#include "head_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LNULL NULL

bool createNode(tPosL *p) {
    *p = malloc(sizeof(struct node));
    return *p != NULL;
}

void CreateEmptyList(tList *L) {
    if (createNode(L))
        (*L)->next = LNULL;
}

bool isEmptyList(tList L) {
    return (L->next == NULL);
}

bool InsertElement(tList *L, char *data) {
    // Inserts an element in the List
    tPosL n;

    /*we check there is enough memory to insert the new element
     if there is not enough memory we return false, otherwise we create a new node*/
    if (!createNode(&n))
        return false;
    /*New node values insertion*/

    n->data.data = malloc(strlen(data) + 1);
    strcpy(n->data.data, data);

    n->data.index = 0;
    n->next = LNULL;

    //if the list is empty we create the head node, which points to the first element of the list

    if ((*L)->next == LNULL)
        (*L)->next = n;
    else {
        //we insert the element at the end
        tPosL p;
        for (p = *L; p->next != LNULL; p = p->next) {
            n->data.index++;
        }
        p->next = n;
    }

    return true;
}

void RemoveElement(tList *L, tPosL p) {
    tPosL i;
    //this function removes an element at a given position, it can't remove the head node
    if (p == NULL)
        return;

    if (p == *L) {
        return;
    } else if (p->next == NULL) {
        for (i = *L; i->next != p; i = i->next);
        i->next = NULL;
    } else {
        i = p->next;
        free(p->data.data);
        p->data.data = strdup(i->data.data);
        p->next = i->next;
        p = i;
    }
    free(p->data.data);
    free(p);
}

void printList(tList L, int num) {

    if (num == -1) {
        //prints the whole list
        for (tPosL p = L->next; p != NULL; p = p->next) {
            printf("%d->%s\n", p->data.index, p->data.data);
        }
    } else if (num > 0) {
        //prints the first num elements of the list
        for (tPosL p = L->next; p != NULL && p->data.index < num; p = p->next) {
            printf("%d->%s\n", p->data.index, p->data.data);
        }
    }

}

void clearList(tList *L) {
    //it removes all the elements except the head node
    tPosL p = (*L)->next;

    while (p != NULL) {
        RemoveElement(L, p);
        p = (*L)->next;
    }

    (*L)->next = NULL;

}

tIteml selectAtPosition(int index, tList L) {
    //it returns an element with a certain index
    if (!isEmptyList(L)) {
        if (index == 0) {
            tPosL p = L->next;
            return p->data;

        }
        for (tPosL p = L->next; p->next != LNULL && p->data.index <= index; p = p->next) {

            if (index == p->data.index)
                return p->data;

        }

    }

    tIteml notFound;
    notFound.data = "Not existing";
    notFound.index = -1;
    return notFound;
}

int retLastIndex(tList L) {
    tPosL p = L;

    while (p->next != NULL) {
        p = p->next;
    }

    return p->data.index;

}

void removeHead(tList *L) {
    if ((*L)->next == NULL) {
        free(*L);
    } else
        printf("This can only remove the head node not the whole list.");
}
