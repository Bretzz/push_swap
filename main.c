/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:19:02 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 23:57:43 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	slot_ready(t_stack *head, int nb);
int	push_ready(t_stack *head, int nb);

/*applie the move 'iter' times
RETURNS: 0 all good, 1 error*/
int	cycle_move(t_stack **head_a, t_stack **head_b, int iter, int (*move)(t_stack **, t_stack **))
{
	int	i;

	i = 0;
	while (i < iter)
	{
		(*move)(head_a, head_b);
		i++;
	}
	return (0);
}

/*sets up 'a' to recive 'nb' from 'b'*/
int	rotate_a(t_stack **head_a, t_stack **head_b, int nb)
{
	size_t	i;
	size_t	len;
	t_stack *temp_a;

	temp_a = *head_a;
	len = ft_stklen(temp_a);
	i = 0;
	while (temp_a && temp_a->nb < nb)
	{
		temp_a = temp_a->next;
		i++;
	}
	if (i > (len / 2))
	{
		i = len - i;
		cycle_move(head_a, head_b, i, &rra);
	}
	else
		cycle_move(head_a, head_b, i, &ra);
	return (i);
}

/*sets up 'b' to push 'nb' to 'a'*/
int	rotate_b(t_stack **head_a, t_stack **head_b, int nb)
{
	size_t	i;
	size_t	len;
	t_stack *temp_b;

	temp_b = *head_b;
	len = ft_stklen(temp_b);
	i = 0;
	while (temp_b && temp_b->nb != nb)
	{
		temp_b = temp_b->next;
		i++;
	}
	if (i > (len / 2))
	{
		i = len - i;
		cycle_move(head_a, head_b, i, &rrb);
	}
	else
		cycle_move(head_a, head_b, i, &rb);
	return (i);
}

/*takes bot the stacks and the element to push as parameters
applies the moves to push the element from 'b' to 'a'
RETURNS: the number of moves applied, -1 if error*/
int	push_it(t_stack **head_a, t_stack **head_b, int nb)
{
	int	moves;

	moves = 0;
	moves += rotate_a(head_a, head_b, nb);
	moves += rotate_b(head_a, head_b, nb);
	pa(head_a, head_b);
	moves++;
	return (moves);
}

/*takes the 'a' stack after the 'migration' and the 'b' stacl as parameters
applies 'sa' if the first number is bigger than the second*/
void	quick_a(t_stack **head_a, t_stack **head_b)
{
	if ((*head_a)->nb > (*head_a)->next->nb)
		sa(head_a, head_b);
}

/*takes bot the stacks as parameters
checks how many moves would it take to push each element of the
stack 'b' in the stack 'a'
RETURNS: the 'cheapest' number to move (considering there are no repetitions)*/
int	cheapest_push(t_stack *head_a, t_stack *head_b)
{
	int		temp_moves;
	int		best_moves;
	int		best;
	t_stack *temp_b;

	best = head_b->nb;
	best_moves = slot_ready(head_a, best) + push_ready(head_b, best) + 1;
	temp_b = head_b->next;
	while (temp_b)
	{
		temp_moves = slot_ready(head_a, temp_b->nb) + push_ready(head_b, temp_b->nb) + 1;
		if (temp_moves < best_moves)
		{
			best_moves = temp_moves;
			best = temp_b->nb;
		}
		temp_b = temp_b->next;
	}
	ft_printf("best=%i, with %i move(s)\n", best, best_moves);
	return (best);
}

/*takes a head pointer and a number as parameter
(the number must be contained in the stack)
RETURNS: the numebr of moves it takes to get the number to the top, -1 if error*/
int	push_ready(t_stack *head, int nb)
{
	size_t	i;
	size_t	len;

	if (!head)
		return (-1);
	len = ft_stklen(head);
	i = 0;
	while (head && head->nb != nb)
	{
		head = head->next;
		i++;
	}
	if (i > (len / 2))
		i = len - i;
	return (i);
}
/*takes an ordered stack (lower to higher, top to bottm, circular ok)
and a number as parameter and returns the number of moves
to make the stack ready to 'recive' the number (from a push)
RETURNS: number of moves, -1 for error*/
int	slot_ready(t_stack *head, int nb)
{
	size_t	i;
	size_t	len;

	if (!head)
		return (-1);
	len = ft_stklen(head);
	i = 0;
	while (head && head->nb < nb)
	{
		head = head->next;
		i++;
	}
	if (i > (len / 2))
		i = len - i;
	return (i);
}

/*moves all the elements from 'a' to 'b' except for 2
RETURNS: the number of moves, 0 for error*/
int	migrate_to_b(t_stack **head_a, t_stack **head_b)
{
	int	i;
	if (!*head_a)
		return (0);
	i = 0;
	while ((*head_a)->next->next)
	{
		pb(head_a, head_b);
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int		moves;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	if (populate_stack(&stack_a, &stack_b, argc, argv))
	{
		ft_stkdel(stack_a);
		ft_stkdel(stack_b);
		return (1);
	}
	print_stack(stack_a, stack_b);
	moves = migrate_to_b(&stack_a, &stack_b);
	if (!moves)
	{
		ft_stkdel(stack_a);
		ft_stkdel(stack_b);
		return (1);
	}
	quick_a(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	while (stack_b)
	{
		ft_printf("curr moves=%i\n", moves);
		moves += push_it(&stack_a, &stack_b, cheapest_push(stack_a, stack_b));
		print_stack(stack_a, stack_b);
		//ft_printf("curr moves=%i\n", moves);
	}
	/* ft_printf("curr moves=%i\n", moves);
	moves += push_it(&stack_a, &stack_b, cheapest_push(stack_a, stack_b));
	print_stack(stack_a, stack_b);
	ft_printf("curr moves=%i\n", moves); */
	ft_stkdel(stack_a);
	ft_stkdel(stack_b);
	return (0);
}
