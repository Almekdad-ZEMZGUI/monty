#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
		stackErr(8, line_number, "add");

	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _nop - doesn’t do anything
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _nop(stack_t **stack, unsigned int lineNumber)
{
	(void)stack;
	(void)lineNumber;
}

/**
 * _sub - subtracts the top element of the stack from the second one
 * @stack: double pointer to top of the stack
 * @lineNumber: line number of of the opcode
 *
 * Return: nothing
 */
void _sub(stack_t **stack, unsigned int lineNumber)
{
	int result;

	if (!stack || !*stack || !(*stack)->next)
                stackErr(8, lineNumber, "sub");

	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
