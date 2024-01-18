/**
 * @file hash_address.c
 * @brief Implementation of a hash table using open addressing.
 * Created by following https://www.youtube.com/watch?v=2Ti5yvumFTU.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (Person*)(0xFFFFFFFF)

typedef struct
{
    char name[MAX_NAME];
    int age;
    // ... add other stuff later
} Person;

// Hash Table is an array of pointers to Person structs
Person* hash_table[TABLE_SIZE];

unsigned int hash(char* name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (size_t i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() 
{
    // Set entire table to be empty
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    printf("Start\n");
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%zu\t---\n", i);
        }
        else if (hash_table[i] == DELETED_NODE)
        {
            printf("\t%zu\t---<deleted>\n", i);
        }
        else
        {
            printf("\t%zu\t%s\n", i, hash_table[i]->name);
        }
    }
    printf("End\n");
}

bool hash_table_insert(Person* p)
{
    if (p == NULL) return false;
    int index = hash(p->name);

    // Linear probing.
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        size_t try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL || hash_table[try] == DELETED_NODE)
        {
            hash_table[try] = p;
            return true;
        }
    }

    // No empty spots in the table.
    return false;
}

Person* hash_table_lookup(char* name)
{
    int index = hash(name);
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        size_t try = (index + i) % TABLE_SIZE;
        if (hash_table[try] == NULL)
            return false;

        if (hash_table[try] == DELETED_NODE)
            continue;

        if (strncmp(name, hash_table[try]->name, MAX_NAME) == 0)
        {
            return hash_table[try];
        }
    }

    // The name was not found in the entire table.
    return NULL;
}

Person* hash_table_delete(char* name)
{
    int index = hash(name);
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        size_t try = (index + i) % TABLE_SIZE;

        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;

        if (strncmp(name, hash_table[try]->name, MAX_NAME) == 0)
        {
            Person* tmp = hash_table[try];
            hash_table[try] = DELETED_NODE;

            return tmp;
        }
    }

    // The name was not found in the entire table.
    return NULL;
}

int main()
{
    init_hash_table();

    Person jacob = {"Jacob", 27};
    Person natalie = {"Natalie", 20};
    Person sara = {"Sara", 10};
    Person ron = {"Ron", 56};
    Person jane = {"Jane", 102};
    Person kobe = {"Kobe", 87};
    Person mary = {"Mary", 33};
    Person lebron = {"Lebron", 11};
    Person trey = {"Trey", 8};
    Person biden = {"Biden", 90};

    hash_table_insert(&jacob);
    hash_table_insert(&natalie);
    hash_table_insert(&sara);
    hash_table_insert(&ron);
    hash_table_insert(&jane);
    hash_table_insert(&kobe);
    hash_table_insert(&mary);
    hash_table_insert(&lebron);
    hash_table_insert(&trey);
    hash_table_insert(&biden);

    print_table();

    Person* tmp2 = hash_table_delete("Jacob");

    print_table();

    return 0;
}