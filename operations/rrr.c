/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:21:54 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 13:28:47 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"rra and rrb at the same time."
RETURNS: 1 all good, 0 error*/
int	rrr(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!*head_a || !(*head_a)->next)
		return (0);
	if (!*head_b || !(*head_b)->next)
		return (0);
	temp_a = ft_stklast(*head_a);
	temp_b = ft_stklast(*head_b);
	ft_stk_semi_last(*head_a)->next = NULL;
	ft_stk_semi_last(*head_b)->next = NULL;
	temp_a->next = *head_a;
	temp_b->next = *head_b;
	*head_a = temp_a;
	*head_b = temp_b;
	ft_printf("rrr\n");
	return (1);
}
