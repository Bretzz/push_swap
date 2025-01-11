/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:45:07 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:30:27 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Shift up all elements of stack 'a' by 1.
The first element becomes the last one"
RETURNS: 0 all good, 1 error*/
int	ra(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;

	(void)(head_b);
	if (!*head_a || !(*head_a)->next)
		return (1);
	temp = (*head_a)->next;
	ft_stklast(*head_a)->next = *head_a;
	(*head_a)->next = NULL;
	*head_a = temp;
	return (0);
}
