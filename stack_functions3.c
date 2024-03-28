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
