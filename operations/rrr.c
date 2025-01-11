/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:21:54 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:18:32 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"rra and rrb at the same time."
RETURNS: 0 all good, 1 error*/
int	rrr(t_stack **head_a, t_stack **head_b)
{
	if (ra(head_a, head_b))
		return (1);
	if (rb(head_a, head_b))
		return (1);
	return (0);
}
