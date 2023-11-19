#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
extern  char **cmd_t;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global structure to use in the functions
 * @l_num: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @buffer: input text
 * @fd: file descriptor
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
	unsigned int l_num;
	char  **arg;
	stack_t *head;
	char *buffer;
	FILE *fd;
} global_t;
int arrlen_t(char **cmd);
int isInteger(char *str);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
char **get_argv(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strdup(char *str);
void str_strip(char *s);
int parse_op(char *code);
void free_t(char **argv);
extern global_t vars;
void exit_f(void);
void free_dlistint(stack_t *head);
stack_t *add_dnodeint(stack_t **head, int n);
size_t dlistint_len(stack_t *h);
void *_realloc(void *ptr, unsigned int prev_size, unsigned int new_size);
#endif
