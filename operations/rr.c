/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:04:50 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:17:24 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"ra and rb at the same time."
RETURNS: 0 all good, 1 error*/
int	rr(t_stack **head_a, t_stack **head_b)
{
	if (ra(head_a, head_b))
		return (1);
	if (rb(head_a, head_b))
		return (1);
	return (0);
}
