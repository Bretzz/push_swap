/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rotator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:11:12 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 13:48:47 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rrr_rra(t_stack **head_a, t_stack **head_b, int a, int b)
{
	cycle_move(head_a, head_b, b, &rrr);
	cycle_move(head_a, head_b, a - b, &rra);
	return (a);
}

static int	rrr_rrb(t_stack **head_a, t_stack **head_b, int a, int b)
{
	cycle_move(head_a, head_b, a, &rrr);
	cycle_move(head_a, head_b, b - a, &rrb);
	return (b);
}

static int	rr_ra(t_stack **head_a, t_stack **head_b, int a, int b)
{
	cycle_move(head_a, head_b, b, &rr);
	cycle_move(head_a, head_b, a - b, &ra);
	return (a);
}

static int	rr_rb(t_stack **head_a, t_stack **head_b, int a, int b)
{
	cycle_move(head_a, head_b, a, &rr);
	cycle_move(head_a, head_b, b - a, &rb);
	return (b);
}

/*takes 2 stacks and the position of the slot and the number to push
Applies the moves to set up both stack for the push optimizing the doubles
(ex: if 'ra' and 'rb' is needed performs 'rr' instead)
RETURNS: the number of moves made*/
int	best_rotator(t_stack **head_a, t_stack **head_b, size_t a, size_t b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_stklen(*head_a);
	len_b = ft_stklen(*head_b);
	if (a > (len_a / 2) && b > (len_b / 2))
	{
		if (len_a - a > len_b - b)
			return (rrr_rra(head_a, head_b, len_a - a, len_b - b));
		else
			return (rrr_rrb(head_a, head_b, len_a - a, len_b - b));
	}
	else if (a <= (len_a / 2) && b <= (len_b / 2))
	{
		if (a > b)
			return (rr_ra(head_a, head_b, a, b));
		else
			return (rr_rb(head_a, head_b, a, b));
	}
	else if (a > (len_a / 2) && b <= (len_b / 2))
		return (rra_rb(head_a, head_b, len_a - a, b));
	else
		return (ra_rrb(head_a, head_b, a, len_b - b));
}
