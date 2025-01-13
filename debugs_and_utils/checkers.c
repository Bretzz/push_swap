/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:39:16 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 01:57:31 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check if the stack is sorted*/
int	stk_issorted(t_stack *head)
{
	int	prev_nb;

	while (head)
	{
		prev_nb = head->nb;
		head = head->next;
		if (head && prev_nb > head->nb)
			return (0);
	}
	return (1);
}

/*takes a string as param and check if it contains a zero
RETURNS: 0 it doesn't, 1 it does*/
int	real_zero(char *s)
{
	while (*s)
	{
		if (*s == '0')
			return (1);
		s++;
	}
	return (0);
}

/*reverse strcmp*/
int	ft_strrcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	while (i && j && s1[i] == s2[j])
	{
		i--;
		j--;
	}
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[j]));
}

/* takes a string and check if it would overflow if we pass it to atoi
NOTE: front and back white spaces should be trrimmed,
also non-digit char inside the number generate an undefined behaviour.
RETURNS: 1 it will, 0 it won't */
int	overflow_check(char *s)
{
	size_t	len;
	
	if (!s)
		return (0);
	len = ft_strlen(s);
	if (len < 10)
		return (0);
	else if (((*s == '-' || *s == '+') && len > 11)
		|| ((*s != '-' && *s != '+') && len > 10))
		return (1);
	else if (*s == '-' && len == 11 && ft_strncmp(s, "-2147483648", 11) > 0)
		return (1);
	else if (*s == '+' && len == 11 && ft_strncmp(s, "+2147483647", 11) > 0)
		return (1);
	else if (*s != '-' && *s != '+' && len == 10
		&& ft_strncmp(s, "2147483647", 10) > 0)
		return (1);
	return (0);
}

/*just leading spaces allowed
RETURNS: 1 all good, 0 error*/
int	valid_int(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

/* check if the arguments passed respect the criteria:
	1. only integers (no floats) bigger than INT_MIN and smaller than INT_MAX
	2. no repetitions
RETURNS: 1 all good, 0 error*/
int	parse_ready(int argc, char *args[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		if (!valid_int(args[i]))
		{
			//ft_printf("invalid int '%s'\n", args[i]);
			return (0);
		}
		if (overflow_check(args[i]))
		{
			//ft_printf("overflowing '%s'\n", args[i]);
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc)
		{
			if (i != j && ft_atoi(args[i]) == ft_atoi(args[j]))
			{
				//ft_printf("double '%s'\n", args[i]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
