/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:04:50 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 05:59:34 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"ra and rb at the same time."
RETURNS: 1 all good, 0 error*/
int	rr(t_stack **head_a, t_stack **head_b)
{
	if (!ra(head_a, head_b))
		return (0);
	if (!rb(head_a, head_b))
		return (0);
	return (1);
}
