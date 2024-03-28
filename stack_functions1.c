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

/**
 * _pint - prints the value at the top of the stack
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _pint(stack_t **stack, unsigned int lineNumber)
{
	if (!stack || !*stack)
		stackErr(6, lineNumber);

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _pop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (!stack || !*stack)
		stackErr(7, lineNumber);

	temp = *stack;
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _swap(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
		stackErr(8, lineNumber, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
