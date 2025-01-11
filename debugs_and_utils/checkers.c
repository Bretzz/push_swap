/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:39:16 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 19:42:34 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
