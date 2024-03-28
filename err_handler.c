#include "monty.h"

/**
 * fileErr - handles the errors
 * @errCode: error codes:
 * 1 -> The user does not give any file or more than one file to the program
 * 2 -> The file provided is not a file that can be opened or read
 * 3 -> The file provided contains an invalid instruction
 * 4 -> When the program is unable to malloc more memory
 * 5 -> When the parameter passed to the instruction "push" is not an int
 *
 * Return: nothing
 */
void fileErr(int errCode, ...)
{
	va_list ag;
	char *opc;
	int line;

	va_start(ag, errCode);
	switch (errCode)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
		        opc = va_arg(ag, char *);
			fprintf(stderr, "Error: Can't open file %s\n", opc);
			break;
		case 3:
			line = va_arg(ag, int);
			opc = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line, opc);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
		        line = va_arg(ag, int);
			fprintf(stderr, "L%d: usage: push integer\n", line);
			break;
		default:
			break;
	}

	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * stackErr - handles the errors
 * @errCode: error codes:
 * 6 -> When the stack it empty for pint
 * 7 -> When the stack it empty for pop
 * 8 -> When stack is too short for operation
 * 9 -> Division by zero
 *
 * Return: nothing
 */
void stackErr(int errCode, ...)
{
	va_list ag;
	char *op;
	int line;

	va_start(ag, errCode);
	switch (errCode)
	{
		case 6:
		        line = va_arg(ag, int);
			fprintf(stderr, "L%d: can't pint, stack empty\n", line);
			break;
		case 7:
		        line = va_arg(ag, int);
			fprintf(stderr, "L%d: can't pop an empty stack\n", line);
			break;
		case 8:
			line = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line, op);
			break;
		case 9:
		        line = va_arg(ag, unsigned int);
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		default:
			break;
	}

	freeNodes();
	exit(EXIT_FAILURE);
}

/**
 * strErr - handles the errors
 * @errCode: error codes:
 * 10 -> number inside a node is outside ASCII bounds
 * 11 -> stack is empty
 *
 * Return: nothing
 */
void strErr(int errCode, ...)
{
	va_list ag;
	int line;

	va_start(ag, errCode);
	line = va_arg(ag, int);
	switch (errCode)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
			break;
		default:
			break;
	}
	freeNodes();
	exit(EXIT_FAILURE);
}

