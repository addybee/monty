#include "monty.h"
/**
 * pop - pushes an element to the stack.
 * @stack: pointer to pointer tohead of the stack
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (arrlen_t(vars.arg) != 1)
	{
		fprintf(stderr, "L%u: usage: pop\n", line_number);
		exit_f();
	}
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n",
				line_number);
		exit_f();
	}
	if ((*stack)->next == NULL)
		*stack = NULL;
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
	}
	free(temp);
	temp = NULL;
}
