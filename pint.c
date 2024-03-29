#include "monty.h"

/**
 * print_top_of_stack - Prints the top element of the stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number in the file
 * Return: No return value
 */
void print_top_of_stack(stack_t **head, unsigned int line_number)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*head)->n);
}
