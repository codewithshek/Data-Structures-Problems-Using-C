#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; 
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

void delete(int key) {
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            hashTable[index] = -1;
            printf("Deleted key %d at index %d\n", key, index);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
    }
    printf("Key %d not found\n", key);
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("[%d] -> %d\n", i, hashTable[i]);
        } else {
            printf("[%d] -> Empty\n", i);
        }
    }
}

int main() {
    initializeTable();
    insert(20);
    insert(30);
    insert(15);
    display();
    delete(30);
    display();
    return 0;
}
