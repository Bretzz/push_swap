/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:08:55 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 13:35:36 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*applie the move 'iter' times
RETURNS: 0 all good, 1 error*/
int	cycle_move(t_stack **head_a, t_stack **head_b,
	int iter, int (*move)(t_stack **, t_stack **))
{
	int	i;

	i = 0;
	while (i < iter)
		i += (*move)(head_a, head_b);
	return (0);
}

/*takes bot the stacks and the element to push as parameters
applies the moves to push the element from 'b' to 'a'
RETURNS: the number of moves applied, -1 if error*/
int	push_it(t_stack **head_a, t_stack **head_b, int nb)
{
	int	moves;

	moves = 0;
	moves += best_rotator(head_a, head_b,
			mini_slot(*head_a, nb), mini_push(*head_b, nb));
	moves += pa(head_a, head_b);
	return (moves);
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
	t_stack	*temp_b;

	best = head_b->nb;
	best_moves = mini_rotator(head_a, head_b, mini_slot(head_a, best),
			mini_push(head_b, best)) + 1;
	temp_b = head_b->next;
	while (temp_b)
	{
		temp_moves = mini_rotator(head_a, head_b,
				mini_slot(head_a, temp_b->nb),
				mini_push(head_b, temp_b->nb)) + 1;
		if (temp_moves < best_moves)
		{
			best_moves = temp_moves;
			best = temp_b->nb;
		}
		temp_b = temp_b->next;
	}
	return (best);
}
