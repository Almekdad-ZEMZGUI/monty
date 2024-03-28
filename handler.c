#include "monty.h"

/**
 * _handler - find the appropriate function for the opcode
 * @opcode: opcode
 * @val: value of opcode
 * @format: storage format
 * @lineNumber: line number
 *
 * Return: nothing
 */
void _handler(char *opcode, char *val, int lineNumber, int format)
{
	int i;
	int flag;

	instruction_t opt[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; opt[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, opt[i].opcode) == 0)
		{
			callFunction(opt[i].f, opcode, val, lineNumber, format);
			flag = 0;
		}
	}
	if (flag == 1)
		fileErr(3, lineNumber, opcode);
}

/**
 * callFunction - Calls the required function
 * @func: Pointer to the required function
 * @op: string of the opcode
 * @val: value of a numeric value
 * @lineNumber: line number for the instruction
 * @format: Format specifier
 *
 * Return: nothing
 */
void callFunction(op_f func, char *op, char *val, int lineNumber, int format)
{
	int flag;
	int i;
	stack_t *node;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (!val)
			fileErr(5, lineNumber);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				fileErr(5, lineNumber);
		}
		node = createNode(atoi(val) * flag);
		if (format == 0)
			func(&node, lineNumber);
		if (format == 1)
			addToQueue(&node, lineNumber);
	}
	else
		func(&head, lineNumber);
}

/**
 * createNode - Creates a node
 * @n: data of the node
 *
 * Return: pointer to the node, or NULL on failure
 */
stack_t *createNode(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
		fileErr(4);

	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * freeNodes - Frees nodes in the stack
 *
 * Return: nothing
 */
void freeNodes(void)
{
	stack_t *temp;

	if (!head)
		return;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * addToQueue - Adds a node to the queue.
 * @newNode: Pointer to the new node.
 * @lineNumber: line number of the opcode.
 */
void addToQueue(stack_t **newNode, __unusd unsigned int lineNumber)
{
	stack_t *temp = head;

	if (!newNode || !*newNode)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *newNode;
		return;
	}

	while (temp->next)
		temp = temp->next;

	temp->next = *newNode;
	(*newNode)->prev = temp;
}

