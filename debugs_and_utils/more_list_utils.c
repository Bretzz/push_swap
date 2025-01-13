/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:48:50 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 13:30:44 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*count the number of string in arr*/
size_t	ft_arrlen(char **arr)
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
	t_stack	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

/*takes a matrix of strings and it's length as parameters
creates the 'stacks' and fills 'a' with the numbers
RETURNS: 1 all good, 0 error*/
int	populate_stack(t_stack **stack_a, t_stack **stack_b, int len, char *args[])
{
	int		i;
	t_stack	*node;

	*stack_a = NULL;
	*stack_b = NULL;
	i = 0;
	while (i < len)
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
