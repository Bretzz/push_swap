/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:06:22 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:30:42 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Shift down all elements of stack 'a' by 1.
The last element becomes the first one."
RETURNS: 0 all good, 1 error*/
int	rra(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	
	(void)(head_b);
	if (!*head_a || !(*head_a)->next)
		return (1);
	temp = ft_stklast(*head_a);
	ft_stk_semi_last(*head_a)->next = NULL;
	temp->next = *head_a;
	*head_a = temp;
	return (0);
}
