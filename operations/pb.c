/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:39:44 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:15:10 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes the pointers to both the list heads
"Take the first element at the top of 'a' and put it at the top of 'b'.
Do nothing (return 1) if 'a' is empty"
RETURNS: 0 all good, 1 error*/
int	pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*next_a;

	if (!head_a)
		return (1);
	next_a = (*head_a)->next;
	(*head_a)->next = *head_b;
	*head_b = *head_a;
	*head_a = next_a;
	return (0);
}
