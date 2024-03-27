#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @newNode: node to push 
 * @lineNumber: line number of  the opcode
 *
 * Return: nothing
 */
void _push(stack_t **newNode, __unusd unsigned int lineNumber)
{
	stack_t *temp;

	if (!newNode || !*newNode)
		exit(EXIT_FAILURE);

	if (!head)
	{
		head = *newNode;
		return;
	}

	temp = head;
	head = *newNode;
	head->next = temp;
	temp->prev = head;
}


/**
 * _pall - prints all the values on the stack
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of  the opcode
 *
 * Returns: nothing
 */
void _pall(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;
        (void) lineNumber;

	if (!stack)
		exit(EXIT_FAILURE);

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
