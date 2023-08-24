#include "monty.h"

/**
 * m_swap - swap top two elements of `stack'
 * @stack: double pointer to head of stack
 * @line_number: line number of current operation
 *
 * Return: void
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	int fn, sn;

	if (st_data.stack_len < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	fn = (*stack)->n;
	sn = (*stack)->next->n;
	(*stack)->n = sn;
	(*stack)->next->n = fn;
}
