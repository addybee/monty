#include "monty.h"
/**
 * parse_op - execute an opcode with respect to their function.
 * @code: is the opcode
 * Return: 1 on success and 0 for failure
 */
int parse_op(char *code)
{
	int k;
	instruction_t arr_t[8] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (k = 0; arr_t[k].opcode; k++)
	{
		if (strcmp(code, arr_t[k].opcode) == 0)
		{
			arr_t[k].f(&vars.head, vars.l_num);
			return (1);
		}
	}
	return (0);
}
/**
 * _getline - gets a line from fd
 * @lineptr: buffer to fill line with
 * @stream: file descriptor
 * @n:length of the buffer
 * Return: num of characters
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	ssize_t rdbyte;
	char *ptr;

	if (!lineptr || !n)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = 1024;
		ptr = malloc(sizeof(char) * (*n));
		if (!ptr)
			return (-1);
		*lineptr = ptr;
	}
	rdbyte = 0;
	while (((ch = getc(stream)) != EOF) && ch != '\n')
	{
		rdbyte++;
		if (rdbyte > ((ssize_t)*n - 2))
		{
			*n *= 2;
			ptr = (char *)_realloc(*lineptr,
					(sizeof(char) * ((*n) / 2)),
					(sizeof(char) * (*n)));
			if (!ptr)
				return (-1);
			*lineptr = ptr;
		}
		(*lineptr)[rdbyte - 1] = ch;
	}
	if (ch == '\n')
	{
		(*lineptr)[rdbyte] = ch;
		(*lineptr)[rdbyte + 1] = '\0';
		return (rdbyte);
	}
	return (-1);
}
/**
 * _strdup - returns a pointer to a new string which is a duplicate of the
 * string str. Memory for the new string is obtained with malloc, and freed
 * @str: string to be copied
 * Return: a pointer to the new str
 */
char *_strdup(char *str)
{
	int i, j;
	char *p;

	i = j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (p == NULL)
		return (p);
	while (j < i)
	{
		p[j] = str[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

/**
 * _realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @prev_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *_realloc(void *ptr, unsigned int prev_size, unsigned int new_size)
{
	char *pp = NULL;
	unsigned int i;

	if (new_size == prev_size)
		return (ptr);
	if (ptr == NULL)
	{
		pp = malloc(new_size);
		if (!pp)
			return (NULL);
		return (pp);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > prev_size)
	{
		pp = malloc(new_size);
		if (!pp)
			return (NULL);
		for (i = 0; i < prev_size; i++)
			pp[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		pp = malloc(new_size);
		if (!pp)
			return (NULL);
		for (i = 0; i < new_size; i++)
			pp[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (pp);
}
