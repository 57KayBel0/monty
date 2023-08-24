#include "monty.h"

/**
 * m_pall - print all values on `stack' starting from the top
 * @stack: double pointer to head of stack
 * @line_number: line number being executed from script file
 *
 * Return: void
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)(line_number);

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;

		if (current == *stack) /* curr reaches circular head */
			return;
	}
}
