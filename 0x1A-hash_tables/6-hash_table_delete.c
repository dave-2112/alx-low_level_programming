#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 *
 * @ht: hash table
 *
 * Description: frees up memory of a hash table
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;
	hash_node_t *next;

	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];

		while (current)
		{
			next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = next;
		}
	}

	free(ht->array);
	free(ht);
}
