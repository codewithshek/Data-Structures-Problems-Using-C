#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int key;
    int value;
} KeyValuePair;

KeyValuePair dictionary[MAX_SIZE];
int size = 0;

    if (size < MAX_SIZE) {
        dictionary[size].key = key;
        dictionary[size].value = value;
        size++;
    } else {
        printf("Dictionary is full!\n");
    }
}

int searchByKey(int key) {
    for (int i = 0; i < size; i++) {
        if (dictionary[i].key == key) {
            return dictionary[i].value;
        }
    }
    return -1; 
}

void deleteByKey(int key) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (dictionary[i].key == key) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            dictionary[i] = dictionary[i + 1];
        }
        size--;
    } else {
        printf("Key not found!\n");
    }
}

void printDictionary() {
    for (int i = 0; i < size; i++) {
        printf("Key: %d, Value: %d\n", dictionary[i].key, dictionary[i].value);
    }
}

int main() {
    addKeyValuePair(1, 10);
    addKeyValuePair(2, 20);
    addKeyValuePair(3, 30);

    printf("Initial List:\n");
    printDictionary();

    int searchKey = 2;
    int searchResult = searchByKey(searchKey);
    if (searchResult != -1) {
        printf("\nSearch result for key %d: %d\n", searchKey, searchResult);
    } else {
        printf("\nKey %d not found!\n", searchKey);
    }

    int deleteKey = 2;
    deleteByKey(deleteKey);

    printf("\nList after deleting key:\n");
    printDictionary();

    return 0;
}
