/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:39:16 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 15:44:58 by topiana-         ###   ########.fr       */
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
int	parse_ready(int len, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		if (!valid_int(args[i]))
			return (0);
		if (overflow_check(args[i]))
			return (0);
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
