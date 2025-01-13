/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:15:48 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 13:29:59 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes an integer as parameter and returns a mallocated node of a stack*/
t_stack	*ft_stknew(int nb)
{
	t_stack	*node;

	node = (t_stack *)malloc(1 * sizeof(t_stack));
	if (!node)
		return (NULL);
	node->nb = nb;
	node->next = NULL;
	return (node);
}

/*takes a head pointer and a node pointer and attach the latter to the
'stack' pointed by the head, if the head is NULL then the head will point
to the node
RETURNS: 0 all good, 1 error*/
int	ft_stkadd_back(t_stack **head, t_stack *node)
{
	if (!node)
		return (1);
	if (!*head)
	{
		*head = node;
		return (0);
	}
	ft_stklast(*head)->next = node;
	return (0);
}

/*takes a pointer to a 'stack' and returns the last element of the list*/
t_stack	*ft_stklast(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		return (NULL);
	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

/*takes a pointer to a 'stack' and returns the element berfore the last one*/
t_stack	*ft_stk_semi_last(t_stack *head)
{
	t_stack	*temp;

	if (!head)
		return (NULL);
	temp = head;
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}
