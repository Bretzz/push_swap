/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:45:03 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 13:46:10 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra_rb(t_stack **head_a, t_stack **head_b, int a, int b)
{
	cycle_move(head_a, head_b, a, &rra);
	cycle_move(head_a, head_b, b, &rb);
	return (a + b);
}

int	ra_rrb(t_stack **head_a, t_stack **head_b, int a, int b)
{
	cycle_move(head_a, head_b, a, &ra);
	cycle_move(head_a, head_b, b, &rrb);
	return (a + b);
}
