#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

/**
 * stack - Stack data structure
 * @stack: Pointer to the top of the stack
 * @top: Index of the top element in the stack
 */
typedef struct stack {
    int stack[STACK_SIZE];
    int top;
} Stack;

/**
 * push - Pushes an element onto the stack
 * @s: Pointer to the stack
 * @value: Value to be pushed onto the stack
 */
void push(Stack *s, int value)
{
    if (s->top == STACK_SIZE - 1)
    {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->stack[++(s->top)] = value;
}

/**
 * pint - Prints the value at the top of the stack
 * @s: Pointer to the stack
 */
void pint(Stack *s)
{
    if (s->top == -1)
    {
        fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", s->stack[s->top]);
}

/**
 * main - Entry point of the Monty interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    Stack stack;
    stack.top = -1;

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        char *token = strtok(line, " \t\n");
        if (token)
        {
            if (strcmp(token, "push") == 0)
            {
                token = strtok(NULL, " \t\n");
                if (token)
                {
                    int value = atoi(token);
                    push(&stack, value);
                }
                else
                {
                    fprintf(stderr, "Error: push requires an argument\n");
                    return EXIT_FAILURE;
                }
            }
            else if (strcmp(token, "pint") == 0)
            {
                pint(&stack);
            }
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
