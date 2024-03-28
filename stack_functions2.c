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
