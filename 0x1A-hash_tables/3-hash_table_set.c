#include "hash_tables.h"

/**
 * check_key - checks key
 *
 * @current: current node
 * @key: key
 * @value: new value of the key
 *
 * Description: check for key in the hash table
 *
 * Return: 1 if present, 0 otherwise
 */
int check_key(hash_node_t *current, char *key, char *value)
{
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = value;
			return (1);
		}
		current = current->next;
	}
	return (0);
}

/**
 * hash_table_set -  set a hashtable key and value
 *
 * @ht: hash table
 * @key: hash table key
 * @value: value of the new elements
 *
 * Description: adds an element to the hash table
 *
 * Return: 1 if success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	char *value_copy;
	char *key_copy;
	hash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	key_copy = strdup(key);
	if (key_copy == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	if (check_key(ht->array[index], key_copy, value_copy) == 1)
		return (1);

	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
	{
		free(new_node);
		return (0);
	}

	new_node->key = key_copy;
	new_node->value = value_copy;
	if (ht->array[index] != NULL)
		new_node->next = ht->array[index];
	else
		new_node->next = NULL;

	ht->array[index] = new_node;

	return (1);
}
