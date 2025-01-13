/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:14:10 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 16:30:54 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*moves all the elements from 'a' to 'b' except for 2
RETURNS: the number of moves, 0 for error*/
int	migrate_to_b(t_stack **head_a, t_stack **head_b)
{
	int	moves;

	if (!*head_a)
		return (0);
	moves = 0;
	while ((*head_a)->next->next)
		moves += pb(head_a, head_b);
	return (moves);
}

/*sets up 'a' to recive 'nb' from 'b'*/
int	rotate_a(t_stack **head_a, t_stack **head_b, int nb)
{
	size_t	i;
	size_t	len;
	t_stack	*temp_a;

	temp_a = *head_a;
	len = ft_stklen(temp_a);
	i = mini_slot(*head_a, nb);
	if (i > (len / 2))
	{
		i = len - i;
		cycle_move(head_a, head_b, i, &rra);
	}
	else
		cycle_move(head_a, head_b, i, &ra);
	return (i);
}

/*takes stack as parameter
rotates it until the lowest number is on top
RERTURNS: the number of moves done, -1 error*/
int	low_on_top(t_stack **head_a, t_stack **head_b)
{
	int		moves;
	int		lowest;
	t_stack	*temp_a;

	temp_a = *head_a;
	lowest = temp_a->nb;
	while (temp_a)
	{
		if (temp_a->nb < lowest)
			lowest = temp_a->nb;
		temp_a = temp_a->next;
	}
	moves = rotate_a(head_a, head_b, lowest);
	return (moves);
}
