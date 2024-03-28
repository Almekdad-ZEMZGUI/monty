#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	openFile(argv[1]);
	freeNodes();
	return (0);
}

/**
 * openFile - opens the file
 * @fileName: the file path
 *
 * Return: nothing
 */
void openFile(char *fileName)
{
	FILE *fd = fopen(fileName, "r");

	if (!fileName || !fd)
		fileErr(2, fileName);

	readFile(fd);
	fclose(fd);
}

/**
 * readFile - reads a file
 * @fd: file descriptor
 *
 * Return: nothing
 */
void readFile(FILE *fd)
{
	int lineNumber, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lineNumber = 1; getline(&buffer, &len, fd) != -1; lineNumber++)
	{
		format = parseLine(buffer, lineNumber, format);
	}

	free(buffer);
}

/**
 * parseLine - Separates lines
 * @buffer: line of the file
 * @lineNumber: line number
 * @format: storage format
 *
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseLine(char *buffer, int lineNumber, int format)
{
	char *opcode, *val;
	const char *delm = "\n ";

	if (buffer == NULL)
		fileErr(4);

	opcode = strtok(buffer, delm);
	if (opcode == NULL)
		return (format);

	val = strtok(NULL, delm);
	if (strcmp(opcode, "stack") == 0)
		return (0);

	if (strcmp(opcode, "queue") == 0)
		return (1);

	_handler(opcode, val, lineNumber, format);

	return (format);
}



