/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:04:50 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 14:16:57 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"ra and rb at the same time."
RETURNS: 1 all good, 0 error*/
int	rr(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!*head_a || !(*head_a)->next)
		return (0);
	if (!*head_b || !(*head_b)->next)
		return (0);
	temp_a = (*head_a)->next;
	temp_b = (*head_b)->next;
	ft_stklast(*head_a)->next = *head_a;
	ft_stklast(*head_b)->next = *head_b;
	(*head_a)->next = NULL;
	(*head_b)->next = NULL;
	*head_a = temp_a;
	*head_b = temp_b;
	ft_printf("rr\n");
	return (1);
}
