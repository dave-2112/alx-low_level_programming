#include "hash_tables.h"

/**
 * key_index - key index of a key
 * @key: key
 * @size: size of the array of the hash table
 *
 * Description: finds the key indes of a string in a hastable and returns it
 *
 * Return: unsigned long int
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2((unsigned char *)key) % size);
}
