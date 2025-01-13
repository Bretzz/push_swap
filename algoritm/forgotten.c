/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forgotten.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:12:25 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 13:38:38 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*functions I don't use anymore but they deserve to live
(this file will not be compiled in the makefile)*/

/*sets up 'b' to push 'nb' to 'a'*/
int	rotate_b(t_stack **head_a, t_stack **head_b, int nb)
{
	size_t	i;
	size_t	len;
	t_stack	*temp_b;

	temp_b = *head_b;
	len = ft_stklen(temp_b);
	i = mini_push(*head_b, nb);
	if (i > (len / 2))
	{
		i = len - i;
		cycle_move(head_a, head_b, i, &rrb);
	}
	else
		cycle_move(head_a, head_b, i, &rb);
	return (i);
}

/*takes a head pointer and a number as parameter
(the number must be contained in the stack)
RETURNS: the numebr of moves to get the number to the top, -1 if error*/
int	push_ready(t_stack *head, int nb)
{
	size_t	i;
	size_t	len;

	if (!head)
		return (-1);
	len = ft_stklen(head);
	i = mini_push(head, nb);
	if (i > (len / 2))
		i = len - i;
	return (i);
}

/*takes an ordered stack (lower to higher, top to bottm, circular ok)
and a number as parameter and returns the number of moves
to make the stack ready to 'recive' the number (from a push)
RETURNS: number of moves, -1 for error*/
int	slot_ready(t_stack *head, int nb)
{
	size_t	i;
	size_t	len;

	if (!head)
		return (-1);
	len = ft_stklen(head);
	i = mini_slot(head, nb);
	if (i > (len / 2))
		i = len - i;
	return (i);
}
