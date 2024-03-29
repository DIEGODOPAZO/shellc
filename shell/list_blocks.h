#ifndef SHELLC_LIST_BLOCKS_H
#define SHELLC_LIST_BLOCKS_H


#include <stdbool.h>
#include <stddef.h>
#include <sys/shm.h>
#define MAX 1024

typedef struct {
    void *address;
    size_t size;
    char time[19];
    char allocation_type[13];
    key_t key;
    char file_name[MAX];
    int file_descriptor;
    int shmid;
} tItemlM;

typedef struct nodeM *tPosLM;

struct nodeM {

    tItemlM data;
    tPosLM next;
};

typedef tPosLM tListM;


void CreateEmptyListM(tListM *L);

bool isEmptyListM(tListM L);

bool InsertElementM(tListM *L, void*address, size_t size, char allocation_type[], int key, char file_name[], int file_descriptor, int shmid);

void RemoveElementM(tListM *L, tPosLM p, int fromListRemove);

void printListM(tListM L, char memType);

void clearListM(tListM *L);

void removeHeadM(tListM *L);

size_t size_of_shared(tListM L, key_t key);

#endif //SHELLC_LIST_BLOCKS_H
