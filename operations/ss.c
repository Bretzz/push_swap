/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:29:25 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 06:00:53 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"sa and sb at the same time."
RETURNS: 1 all good, 0 error*/
int	ss(t_stack **head_a, t_stack **head_b)
{
	if (!sa(head_a, head_b))
		return (0);
	if (!sb(head_a, head_b))
		return (0);
	return (1);
}
