/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:32:22 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 05:58:47 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Take the first element at the top of 'b' and put it at the top of 'a'.
Do nothing (return 0) if 'b' is empty"
RETURNS: 1 all good, 0 error*/
int	pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*next_b;

	if (!*head_b)
		return (0);
	next_b = (*head_b)->next;
	(*head_b)->next = *head_a;
	*head_a = *head_b;
	*head_b = next_b;
	return (1);
}
