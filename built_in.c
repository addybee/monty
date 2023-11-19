#include "monty.h"
/**
 * push - pushes an element to the stack.
 * @stack: pointer to pointer tohead of the stack
 * @line_number: the line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!vars.arg || arrlen_t(vars.arg) != 2 || !isInteger(vars.arg[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit_f();
	}
	new = add_dnodeint(stack, atoi(vars.arg[1]));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		exit_f();
	}
}
/**
 * pall - prints all the values on the stack, starting from the top.
 * @stack: pointer to pointer tohead of the stack
 * @line_number: the line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (arrlen_t(vars.arg) != 1)
	{
		fprintf(stderr, "L%u: usage: pall\n", line_number);
		exit_f();
	}

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * exit_f - it exit the program with EXIT_FAILURE
 */
void exit_f(void)
{
	if (vars.buffer)
	{
		free(vars.buffer);
		vars.buffer = NULL;
	}
	if (vars.arg)
	{
		free_t(vars.arg);
		vars.arg = NULL;
	}
	free_dlistint(vars.head);
	fclose(vars.fd);
	exit(EXIT_FAILURE);
}
/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @stack: pointer to pointer to head of the stack
 * @line_number: the line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (arrlen_t(vars.arg) != 1)
	{
		fprintf(stderr, "L%u: usage: pall\n", line_number);
		exit_f();
	}
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n",
				line_number);
		exit_f();
	}
	printf("%d\n", (*stack)->n);
}
