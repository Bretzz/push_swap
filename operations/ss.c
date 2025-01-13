/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:29:25 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 16:10:47 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"sa and sb at the same time."
RETURNS: 1 all good, 0 error*/
int	ss(t_stack **head_a, t_stack **head_b)
{
	t_stack	*third_a;
	t_stack	*third_b;
	t_stack	*second_a;
	t_stack	*second_b;

	if (!*head_a || !(*head_a)->next)
		return (0);
	if (!*head_b || !(*head_b)->next)
		return (0);
	third_a = (*head_a)->next->next;
	third_b = (*head_b)->next->next;
	second_a = (*head_a)->next;
	second_b = (*head_b)->next;
	(*head_a)->next = third_a;
	(*head_b)->next = third_b;
	second_a->next = *head_a;
	second_b->next = *head_b;
	*head_a = second_a;
	*head_b = second_b;
	ft_printf("ss\n");
	return (1);
}
