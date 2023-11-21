#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
global_t vars = {0, NULL, NULL, NULL, NULL};
/**
 * check_file - checks if the file exists and if the file can
 * be opened
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_file(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], F_OK) != 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

/**
 * main - program entry
 * @argc: number of command line argument
 * @argv: command line argument
 * Return: 0 when successful or 1 when failed
 */
int main(int argc, char **argv)
{
	size_t input_len = 0;
	FILE *fd = check_file(argc, argv);

	vars.fd = fd;
	while (_getline(&vars.buffer, &input_len, fd) != -1)
	{
		vars.l_num++;
		str_strip(vars.buffer);
		if (strlen(vars.buffer) <= 0)
		{
			free(vars.buffer);
			vars.buffer = NULL;
			continue;
		}
		vars.arg = get_argv(vars.buffer);

		if (!parse_op(vars.arg[0]))
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
				       vars.l_num, vars.arg[0]);
			exit_f();
		}
		free(vars.buffer);
		free_t(vars.arg);
		vars.buffer = NULL;
		vars.arg = NULL;
	}
	free(vars.buffer);
	fclose(fd);
	free_dlistint(vars.head);
	return (0);
}
