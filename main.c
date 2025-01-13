/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:19:02 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 18:53:41 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*prints a matrix of strings*/
void	ft_print_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}

/*takes a head pointer as parameter and prints the whole stack*/
void	print_stack(t_stack *head_a, t_stack *head_b)
{
	while (head_a || head_b)
	{
		if (head_a)
		{
			ft_printf("%i", head_a->nb);
			head_a = head_a->next;
		}
		else
			ft_printf(" ");
		ft_printf(" ");
		if (head_b)
		{
			ft_printf("%i", head_b->nb);
			head_b = head_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("- -\na b\n\n");
}

/*parses the input and populates the stack
RETURNS: 0 all good, 1 error*/
static int	clean_populate(t_stack **stack_a, t_stack **stack_b,
	int len, char **args)
{
	if (!parse_ready(len, args))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!populate_stack(stack_a, stack_b, len, args))
	{
		ft_stkdel(*stack_a);
		ft_stkdel(*stack_b);
		return (1);
	}
	return (0);
}

/*checks for input validity and sets up the stacks
RETURNS: 0 all good, 1 error*/
static int	clean_startup(t_stack **stack_a, t_stack **stack_b,
	int argc, char *argv[])
{
	char	**args;
	size_t	len;

	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		len = ft_arrlen(args);
		if (len <= 1)
		{
			ft_free_arr(args);
			return (1);
		}
	}
	else
	{
		args = &argv[1];
		len = argc - 1;
	}
	if (!clean_populate(stack_a, stack_b, len, args))
		len = 0;
	if (argc == 2)
		ft_free_arr(args);
	return (len);
}

int	main(int argc, char *argv[])
{
	int		moves;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (clean_startup(&stack_a, &stack_b, argc, argv))
		return (1);
	if (stk_issorted(stack_a))
		return (0);
	moves = 0;
	moves += migrate_to_b(&stack_a, &stack_b);
	while (stack_b)
		moves += push_it(&stack_a, &stack_b, cheapest_push(stack_a, stack_b));
	moves += low_on_top(&stack_a, &stack_b);
	ft_stkdel(stack_a);
	ft_stkdel(stack_b);
	return (0);
}
