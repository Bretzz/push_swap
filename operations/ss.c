/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:29:25 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:19:48 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"sa and sb at the same time."
RETURNS: 0 all good, 1 error*/
int	ss(t_stack **head_a, t_stack **head_b)
{
	if (sa(head_a, head_b))
		return (1);
	if (sb(head_a, head_b))
		return (1);
	return (0);
}
