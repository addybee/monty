#include "monty.h"
/**
 * arrlen_t - finds the length of array
 * @cmd: array of string
 * Return: lenth of the aarray
 */
int arrlen_t(char **cmd)
{
	int i = 0;

	if (!cmd)
		return (i);
	while (cmd[i] != NULL)
	{
		i++;
	}
	return (i);
}
/**
 * isInteger - check if str is an integer
 * @str: str to check if an int
 * Return: 1 if successful and 0 otherwise
 */

int isInteger(char *str)
{
	char *endptr;

	strtol(str, &endptr, 10);
	return (*str != '\0' && *endptr == '\0');
}

/**
 * get_argv - convert the string from input to array of string
 * @command: pointer to the string from input.
 * Return: array to strings of the converted input string when successful
 * NULL when failed
 */
char **get_argv(char *command)
{
	char *command_dup = NULL, *command_tok = NULL, *str = NULL;
	char **argv = NULL;
	int i = 0;

	if (command == NULL)
		return (NULL);
	command_dup = _strdup(command);
	for (i = 1, str = command_dup; ; i++, str = NULL)
	{
		command_tok = strtok(str, " ");
		if (!command_tok)
			break;
	}
	free(command_dup);
	argv = malloc(sizeof(char *) * i);
	if (argv == NULL)
		return (NULL);
	for (i = 0, str = command; ; str = NULL, i++)
	{
		command_tok = strtok(str, " ");
		if (!command_tok)
		{
			argv[i] = command_tok;
			break;
		}
		argv[i] = malloc((1 + strlen(command_tok)) * sizeof(char));
		if (argv[i] == NULL)
		{
			i--;
			while (i >= 0)
			{
				free(argv[i]);
				i--;
			}
			free(argv);
			return (NULL);
		}
		strcpy(argv[i], command_tok);
	}
	return (argv);
}

/**
 * str_strip - strip leading and trailing whitespace from a string
 * @s: The string to search.
 * Return: void
 */
void str_strip(char *s)
{
	int i, j, len;

	if (s == NULL)
		return;
	len = strlen(s);
	/* Find the index of the first non-whitespace character */
	for (i = 0; ((i < len) && (s[i] == ' ' ||
				s[i] == '\t' || s[i] == '\n')); i++)
	{};
	/* Shift the non-whitespace characters to the beginning of the string*/
	for (j = 0; i < len; i++, j++)
	{
		s[j] = s[i];
	}
	s[j] = '\0';

	/*
	 * Striping whitespace character at the end of a string
	 * Start from the end of the string and move backwards
	*/
	len = strlen(s);
	for (i = (len - 1); i >= 0; i--)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			/*
			 * Replace white space characters with null terminators
			*/
			s[i] = '\0';
		}
		else
		{
			/*
			 * Stop when a non-white space character is encountered
			*/
			break;
		}
	}
}

/**
 * free_t - free the allocated memory for arguements
 * @argv: pointer to array of the arguement
 * Return: void
 */
void free_t(char **argv)
{
	int i = 0;

	if (!argv)
		return;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}
