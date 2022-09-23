#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 *
 * @ht: hash table
 *
 * Description: prints the key value pairs of has table
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;
	int element = 0;

	if (ht == NULL)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			if (element != 0)
				printf(", ");
			printf("\'%s\': ", current->key);
			printf("\'%s\'", current->value);
			current = current->next;
			element++;
		}
	}
	printf("}\n");
}
