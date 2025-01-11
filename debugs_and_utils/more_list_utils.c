/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:48:50 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 23:05:42 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes a head pointer as a parameter
RETURNS the number of nodes linked, 0 if the head is NULL*/
size_t	ft_stklen(t_stack *head)
{
	size_t	i;

	if (!head)
		return (0);
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

/*takes a head pointer as a parameter,
deletes the 'stack' pointed by the head*/
void	ft_stkdel(t_stack *head)
{
	t_stack *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

/*takes both argc and argv as params
creates the 'stacks' and fills 'a' with the numbers
RETURNS: 0 all good, 1 error*/
int	populate_stack(t_stack **stack_a, t_stack **stack_b, int argc, char *argv[])
{
	int	i;
	int	nb;
	t_stack	*node;
	
	*stack_a = NULL;
	*stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (!nb && !real_zero(argv[i]))
		{
			ft_printf("'%s' wrong parameter\n", argv[i]);
			return (1);
		}
		node = ft_stknew(ft_atoi(argv[i]));
		if (!node)
		{
			ft_printf("malloc failure :/\n");
			return (1);
		}
		ft_stkadd_back(stack_a, node);
		i++;
	}
	return (0);
}
