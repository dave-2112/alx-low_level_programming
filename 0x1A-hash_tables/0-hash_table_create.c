#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table.
 *
 * @size: the size of the array to be created
 * Return: hash_table_t*
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *main_list;
	unsigned long int iter;

	main_list = malloc(sizeof(hash_table_t));
	if (main_list == NULL)
		return (NULL);
	main_list->size = size;
	main_list->array = malloc(sizeof(hash_node_t *) * size);
	if (main_list->array == NULL)
		return (NULL);
	for (iter = 0; iter < size; iter++)
		main_list->array[iter] = NULL;
	return (main_list);
}
