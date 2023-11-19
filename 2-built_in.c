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
/**
 * swap- swaps the top two elements of the stack..
 * @stack: pointer to pointer to head of the stack
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int k;

	if (arrlen_t(vars.arg) != 1)
	{
		fprintf(stderr, "L%u: usage: pop\n", line_number);
		exit_f();
	}
	if (dlistint_len(*stack) < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		exit_f();
	}
	k = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = k;
}

