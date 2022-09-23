#include "hash_tables.h"

/**
 * hash_table_get - gets the value of a key
 *
 * @ht: hash table
 * @key: key
 *
 * Description: returns the value of a key in a hash table
 *
 * Return: value, otherwise NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	if (ht->array[index] == NULL)
		return (NULL);

	current = ht->array[index];
	while (current)
	{
		if (strcmp(current->key, key) == 0)
		{
			return (current->value);
		}
		current = current->next;
	}

	return (NULL);
}
