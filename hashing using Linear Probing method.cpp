#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

// Hash Table structure
typedef struct {
    int key;
    int value;
} HashTableEntry;

// Initialize Hash Table
void initialize(HashTableEntry table[], int size) {
    for (int i = 0; i < size; i++) {
        table[i].key = -1;
    }
}

// Hash Function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert an element into Hash Table
void insert(HashTableEntry table[], int size, int key, int value) {
    int index = hash(key);
    int originalIndex = index;

    while (table[index].key != -1) {
        index = (index + 1) % size;

        // If we come back to the original index, the table is full
        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert.\n");
            return;
        }
    }

    table[index].key = key;
    table[index].value = value;
}

// Search for a key in Hash Table
int search(HashTableEntry table[], int size, int key) {
    int index = hash(key);
    int originalIndex = index;

    while (table[index].key != -1) {
        if (table[index].key == key) {
            return table[index].value;
        }

        index = (index + 1) % size;

        // If we come back to the original index or find an empty slot, the key is not present
        if (index == originalIndex || table[index].key == -1) {
            return -1;
        }
    }

    return -1;
}

int main() {
    HashTableEntry hashTable[TABLE_SIZE];
    initialize(hashTable, TABLE_SIZE);

    insert(hashTable, TABLE_SIZE, 23, 100);
    insert(hashTable, TABLE_SIZE, 14, 200);
    insert(hashTable, TABLE_SIZE, 7, 300);
    insert(hashTable, TABLE_SIZE, 37, 400);
    insert(hashTable, TABLE_SIZE, 18, 500);

    printf("Value for key 7: %d\n", search(hashTable, TABLE_SIZE, 7));
    printf("Value for key 37: %d\n", search(hashTable, TABLE_SIZE, 37));
    printf("Value for key 14: %d\n", search(hashTable, TABLE_SIZE, 14));
    printf("Value for key 22: %d\n", search(hashTable, TABLE_SIZE, 22));

    return 0;
}

