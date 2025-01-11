/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:35:10 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:32:13 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		//ft_printf("adding %s...\n", argv[i]);
		ft_stkadd_back(&stack_a, ft_stknew(ft_atoi(argv[i])));
		i++;
	}
	print_stack(stack_a, stack_b);
	
	ft_printf("pb\n");
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_printf("pa\n");
	pa(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_printf("ra ra\n");
	ra(&stack_a, &stack_b);
	ra(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_printf("pb pb pb \n");
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	
	ft_printf("rb\n");
	rb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_printf("rrb rrb\n");
	rrb(&stack_a, &stack_b);
	rrb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_printf("rra\n");
	rra(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_printf("sa sb\n");
	sa(&stack_a, &stack_b);
	sb(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_printf("rrr\n");
	rrr(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);

	ft_printf("ss\n");
	ss(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
	return (0);
}