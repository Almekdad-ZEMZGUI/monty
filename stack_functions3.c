#include "monty.h"

/**
 * _mod - modulo of the second top element of the stack by the top one
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _mod(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
                stackErr(8, lineNumber, "mod");

	if ((*stack)->n == 0)
		stackErr(9, lineNumber);

	(*stack) = (*stack)->next;
	result = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _pchar(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (!stack || !*stack)
		strErr(11, lineNumber);

	result = (*stack)->n;
	if (result < 0 || result > 127)
		strErr(10, lineNumber);
	printf("%c\n", result);
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _pstr(stack_t **stack, __unusd unsigned int lineNumber)
{
	int asc;
	stack_t *temp = *stack;

	if (!stack || !*stack)
	{
		printf("\n");
		return;
	}

	while (temp)
	{
		asc = temp->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _rotl(stack_t **stack, __unusd unsigned int lineNumber)
{
	stack_t *temp = *stack;

	if (!stack || !*stack || !(*stack)->next)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _rotr(stack_t **stack, __unusd unsigned int lineNumber)
{
	stack_t *temp = *stack;

	if (!stack || !*stack || !(*stack)->next)
		return;

	while (temp->next)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
