/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:48:50 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/12 14:47:47 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

size_t ft_arrlen(char **arr)
{
	size_t	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

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
RETURNS: 1 all good, 0 error*/
int	populate_stack(t_stack **stack_a, t_stack **stack_b, int argc, char *args[])
{
	int	i;
	t_stack	*node;
	
	*stack_a = NULL;
	*stack_b = NULL;
	//ft_printf("populating:\n");
	//ft_print_arr(args);
	i = 0;
	while (i < argc)
	{
		node = ft_stknew(ft_atoi(args[i]));
		if (!node)
		{
			ft_printf("malloc failure :/\n");
			return (0);
		}
		ft_stkadd_back(stack_a, node);
		i++;
	}
	return (1);
}

/*frees a array of char pointers*/
int	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
