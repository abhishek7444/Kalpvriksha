#include<stdio.h>
#include<stdlib.h>
 
#define HASHTABLE_SIZE 10
 
struct node {
    int key;
    int value;
    struct node* next;
}*hashTable[HASHTABLE_SIZE], * newNode, * temp;
 
void insert() {
    int value, key;
    printf("Enter Key: ");
    scanf("%d", &key);
    printf("Enter Value: ");
    scanf("%d", &value);
    printf("\n");
    if (value < 0 || key < 0) {
        printf("Enter non negative value\n");
    }
    int index = key % HASHTABLE_SIZE;
 
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
 
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    }
    else {
        temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
 
void search() {
    int key;
    int value;
    int found = 0;
    printf("Enter key: ");
    scanf("%d", &key);
    int index = key % HASHTABLE_SIZE;
    if (hashTable[index] == NULL) {
        found = 0;
    }
    else {
        temp = hashTable[index];
        while (temp != NULL) {
            if (temp->key == key) {
                found = 1;
                value = temp->value;
                break;
            }
            temp = temp->next;
        }
    }
    if (found) {
        printf("Value: %d ", value);
    }
    else {
        printf("key %d not present\n", key);
    }
    printf("\n\n");
}
 
void display() {
    printf("Hash Table:\n");
    for (int i = 0;i < HASHTABLE_SIZE;i++) {
        if (hashTable[i] == NULL) {
            continue;
        }
        else {
            int first = 1;
            printf("Index %d: ", i);
            temp = hashTable[i];
            while (temp != NULL) {
                if (!first)printf(" -> ");
                printf("( %d,%d )", temp->key, temp->value);
                first = 0;
                temp = temp->next;
            }
            printf("\n");
        }
    }
    printf("\n\n");
}
 
void delete() {
    int key;
    printf("Enter key: ");
    scanf("%d", &key);
    int index = key % HASHTABLE_SIZE;
    struct node* prev = NULL;
    if (hashTable[index] == NULL) {
        printf("Key %d not present\n");
    }
    else {
        temp = hashTable[index];
        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == NULL) {
                    hashTable[index] = temp->next;
                }
                else {
                    prev->next = temp->next;
                }
                printf("Key %d deleted. ", key);
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    printf("\n\n");
}
 
int main() {
    int choice, numberOfOperation;
    scanf("%d", &numberOfOperation);
 
    while (numberOfOperation) {
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:insert();
            break;
        case 2:search();
            break;
        case 3:delete();
            break;
        case 4:display();
            break;
        case 5:printf("Existing Program.\n\n");
            return 0;
        default:printf("Wrong Choice\n");
            break;
        }
        numberOfOperation--;
    }
}
