/// Courtesy of the original source code:
/// https://youtu.be/wg8hZxMRwcw?list=PLlcnQQJK8SUiy94wgp27jqRNqGw-OY50R

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLESIZE 3

typedef struct entry_t
{
    char *key;
    char *value;
    struct entry_t *next;
} entry_t;

typedef struct
{
    entry_t **entries;
} ht_t;

ht_t *ht_create(void)
{
    /// allocate the hashtable
    ht_t *hashtable = malloc(sizeof(ht_t) * 1);

    /// allocate table entries
    hashtable->entries = malloc(sizeof(entry_t *) * TABLESIZE);

    /// set each to null (needed for proper operation)
    for (int i = 0; i < TABLESIZE; ++i)
    {
        hashtable->entries[i] = NULL;
    }

    return hashtable;
}

/// Hash a key
unsigned int hash(const char *key)
{
    /// Initialize value, which is the slot, at 0
    unsigned long int value = 0;
    /// Indexing the char *key
    unsigned int i = 0;
    /// Number of characters
    unsigned int key_len = strlen(key);

    /// Generates the slot's value
    for (; i < key_len; i++)
    {
        value = value * 37 + key[i];
    }

    /// And set the slot's value to this remainder to fit the tablesize.
    value = value % TABLESIZE;

    return value;
}

entry_t *ht_pair(const char *key, const char *value)
{
    /// allocate the entry
    entry_t *entry = malloc(sizeof(entry) * 1);
    entry->key = malloc(strlen(key) + 1);
    entry->value = malloc(strlen(value) + 1);

    /// copy the key and value in place
    strcpy(entry->key, key);
    strcpy(entry->value, value);

    /// next starts out null but may be set later on
    entry->next = NULL;

    return entry;
}

void ht_set(ht_t *hashtable, const char *key, const char *value)
{
    unsigned int slot = hash(key);

    /// try to look up an entry set by key
    entry_t *entry = hashtable->entries[slot];

    /// no entry means slot is empty, insert immediately
    if (entry == NULL)
    {
        hashtable->entries[slot] = ht_pair(key, value);
        return;
    }

    entry_t *prev;

    /// walk through each entry until either the end is reached or a matching key is found
    while (entry != NULL)
    {
        /// check key
        if (strcmp(entry->key, key) == 0)
        {
            /// match found, replace Value
            free(entry->value);
            entry->value = malloc(strlen(value) + 1);
            strcpy(entry->value, value);
            return;
        }

        /// walk to next
        prev = entry;
        entry = prev->next;
    }

    prev->next = ht_pair(key, value);
}

char *ht_get(ht_t *hashtable, const char *key)
{
    unsigned int slot = hash(key);

    /// try to find a valid slot
    entry_t *entry = hashtable->entries[slot];

    /// no slot means no entry
    if (entry == NULL)
    {
        return NULL;
    }

    while (entry != NULL)
    {
        /// return a value if found
        if (strcmp(entry->key, key) == 0)
        {
            return entry->value;
        }

        /// proceed to next key if available
        entry = entry->next;
    }

    /// reaching here means there were >= 1 entries but no match key
    return NULL;
}

void ht_dump(ht_t *hashtable)
{
    for (int i = 0; i < TABLESIZE; ++i)
    {
        entry_t *entry = hashtable->entries[i];
        if (entry == NULL)
            continue;

        printf("slot[%4d]: ", i);

        for (;;)
        {
            printf("%s=%s ", entry->key, entry->value);
            if (entry->next == NULL)
            {
                break;
            }

            entry = entry->next;
        }

        printf("\n");
    }
}

int main(int argc, char **argv)
{

    ht_t *ht = ht_create();

    ht_set(ht, "name1", "bogdan");
    ht_set(ht, "name2", "franco");
    ht_set(ht, "name3", "einstein");
    ht_set(ht, "name4", "doggo");

    ht_dump(ht);

    return 0;
}