#include <stdio.h>
#define SIZE 10

int hashTable[SIZE] = {-1}; // Initialize with -1 (empty)

// Simple hash function
int hash(int key)
{
    return key % SIZE;
}

// Insert key into hash table
void insert(int key)
{
    int index = hash(key);
    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE; // Linear probing
    }
    hashTable[index] = key;
}

// Search for key in hash table
int search(int key)
{
    int index = hash(key);
    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            return index; // Found
        }
        index = (index + 1) % SIZE;
        if (index == hash(key)) break; // Full loop
    }
    return -1; // Not found
}

// Main function
int main()
{
    insert(25);
    insert(35);
    insert(15); // Collision at 25%10=5, so goes to next slot

    printf("Search 25: Found at index %d\n", search(25));
    printf("Search 40: %s\n", search(40) == -1 ? "Not Found" : "Found");

    return 0;
}
