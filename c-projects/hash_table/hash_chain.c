/**
 * @file hash_address.c
 * @brief Implementation of a hash table using external chaining.
 * Created by following https://www.youtube.com/watch?v=2Ti5yvumFTU.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct Person
{
    char name[MAX_NAME];
    int age;
    struct Person* next;
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
    printf("-------------------------------\n");
    for (size_t i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%zu\t---\n", i);
        }
        else
        {
            printf("\t%zu\t", i);
            Person* tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s -> ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("-------------------------------\n");
}

bool hash_table_insert(Person* p)
{
    if (p == NULL) return false;
    int index = hash(p->name);

    // Replace the current start of the linked-list with p.
    p->next = hash_table[index];
    hash_table[index] = p;

    return true;
}

Person* hash_table_lookup(char* name)
{
    int index = hash(name);

    Person* tmp = hash_table[index];
    while (tmp != NULL && strncmp(name, tmp->name, MAX_NAME) != 0)
    {
        tmp = tmp->next;
    }    
    return tmp;
}

Person* hash_table_delete(char* name)
{
    int index = hash(name);

    Person* tmp = hash_table[index];
    Person* prev = NULL;
    while (tmp != NULL && strncmp(name, tmp->name, MAX_NAME) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    } 

    if (tmp == NULL) return NULL; // No match found.
    
    // The node to delete was the head of the linked-list.
    if (prev == NULL)
    {
        hash_table[index] = tmp->next;     
    }
    else
    {
        prev->next = tmp->next;
    }

    return tmp;
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