#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#define __unusd __attribute__((unused))


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*op_f)(stack_t **, unsigned int);
extern stack_t *head;

/* main */
void openFile(char *fileName);
void readFile(FILE *fd);
int parseLine(char *buffer, int lineNumber, int format);

/* handler */
void _handler(char *opc, char *val, int lineNumber, int format);
void callFunction(op_f func, char *opc, char *val, int lineNumber, int format);
stack_t *createNode(int n);
void freeNodes(void);
void addToQueue(stack_t **newNode, __unusd unsigned int lineNumber);

/* stack_functions1 */
void _push(stack_t **newNode, __unusd unsigned int lineNumber);
void _pall(stack_t **stack, unsigned int lineNumber);
void _pint(stack_t **stack, unsigned int lineNumber);
void _pop(stack_t **stack, unsigned int lineNumber);
void _swap(stack_t **stack, unsigned int lineNumber);

/* stack_functions2 */
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _sub(stack_t **stack, unsigned int lineNumber);
void _div(stack_t **stack, unsigned int lineNumber);
void _mul(stack_t **stack, unsigned int lineNumber);

/* err_handler */
void fileErr(int errCode, ...);
void stackErr(int errCode, ...);
void strErr(int errCode, ...);
#endif /* _MONTY_H_ */
