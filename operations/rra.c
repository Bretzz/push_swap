/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:06:22 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 05:59:45 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Shift down all elements of stack 'a' by 1.
The last element becomes the first one."
RETURNS: 1 all good, 0 error*/
int	rra(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	
	(void)(head_b);
	if (!*head_a || !(*head_a)->next)
		return (0);
	temp = ft_stklast(*head_a);
	ft_stk_semi_last(*head_a)->next = NULL;
	temp->next = *head_a;
	*head_a = temp;
	return (1);
}
