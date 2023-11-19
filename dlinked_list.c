#include "monty.h"
/**
 * free_dlistint - frees a stack_t list.
 * @head: pointer to the dlistint head
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	if (!head)
		return;
	temp = head;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * add_dnodeint - adds a new node at the beginning of stack
 * @head: pointer to pointer of first node of the stack.
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new, *temp;

	if (!head)
		return (NULL);
	new = (stack_t *)malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	temp = *head;
	if (temp == NULL)
		*head = new;
	else
	{
		*head = new;
		new->next = temp;
		temp->prev = new;
	}
	return (new);
}
