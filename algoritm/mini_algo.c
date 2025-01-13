/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:10:05 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 13:33:01 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* slot_ready helperr (also useful to rotate_a)
RETURNS: the number of moves to make the stack ready to
'recive' the number 'nb' with only 'ra'*/
int	mini_slot(t_stack *head, int nb)
{
	int	i;
	int	prev_nb;

	i = 0;
	while (head && head->nb > nb)
	{
		prev_nb = head->nb;
		head = head->next;
		i++;
		if (head && prev_nb > head->nb)
			break ;
	}
	while (head && head->nb < nb)
	{
		prev_nb = head->nb;
		head = head->next;
		i++;
		if (head && prev_nb > head->nb)
			break ;
	}
	return (i);
}

/*push_ready helperr, also useful in push_it*/
int	mini_push(t_stack *head, int nb)
{
	int	i;

	i = 0;
	while (head && head->nb != nb)
	{
		head = head->next;
		i++;
	}
	return (i);
}

/*counts the number of moves that 'best_rotator' would do*/
int	mini_rotator(t_stack *head_a, t_stack *head_b, size_t a, size_t b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_stklen(head_a);
	len_b = ft_stklen(head_b);
	if (a > (len_a / 2) && b > (len_b / 2))
	{
		if (len_a - a > len_b - b)
			return (len_a - a);
		else
			return (len_b - b);
	}
	else if (a <= (len_a / 2) && b <= (len_b / 2))
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (a > (len_a / 2) && b <= (len_b / 2))
		return (len_a - a + b);
	else
		return (a + len_b - b);
}
