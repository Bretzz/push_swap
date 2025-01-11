/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:19:02 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 20:33:39 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*takes an ordered stack (lower to higher, top to bottm, circular ok)
and a number as parameter and returns the number of moves
to make the stack ready to 'recive' the number (from a push)
RETURNS: number of moves, 0 for error*/
int	slot_ready(t_stack *head, int nb)
{
	
}

/*moves all the elements from 'a' to 'b' except for 2
RETURNS: the number of moves, 0 for error*/
int	migrate_to_b(t_stack **head_a, t_stack **head_b)
{
	int	i;
	if (!*head_a)
		return (0);
	i = 0;
	while ((*head_a)->next->next)
	{
		pb(head_a, head_b);
		i++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int		moves;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	if (populate_stack(&stack_a, &stack_b, argc, argv))
	{
		ft_stkdel(stack_a);
		ft_stkdel(stack_b);
		return (1);
	}
	print_stack(stack_a, stack_b);
	moves = migrate_to_b(&stack_a, &stack_b);
	if (!moves)
	{
		ft_stkdel(stack_a);
		ft_stkdel(stack_b);
		return (1);
	}
	print_stack(stack_a, stack_b);
	ft_stkdel(stack_a);
	ft_stkdel(stack_b);
	return (0);
}
