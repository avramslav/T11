#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);

void close_doors(struct door *doors);

void print_doors(struct door *doors);

void sort_doors(struct door *doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort_doors(doors);
    close_doors(doors);
    print_doors(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void print_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
    printf("%d, %d", doors[DOORS_COUNT - 1].id, doors[DOORS_COUNT - 1].status);
}

void sort_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        for (int j = 0; j < DOORS_COUNT; j++)
            if (doors[i].id < doors[j].id) {
                struct door tmp = doors[i];
                doors[i] = doors[j];
                doors[j] = tmp;
            }
}

void close_doors(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT - 1; i++) {
        doors[i].status = 0;
    }
}