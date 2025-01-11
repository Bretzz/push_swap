/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:16:01 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/11 23:05:50 by topiana-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

//operations
int		sa(t_stack **head_a, t_stack **head_b);
int		sb(t_stack **head_a, t_stack **head_b);
int		ss(t_stack **head_a, t_stack **head_b);
int		pa(t_stack **head_a, t_stack **head_b);
int		pb(t_stack **head_a, t_stack **head_b);
int		ra(t_stack **head_a, t_stack **head_b);
int		rb(t_stack **head_a, t_stack **head_b);
int		rr(t_stack **head_a, t_stack **head_b);
int		rra(t_stack **head_a, t_stack **head_b);
int		rrb(t_stack **head_a, t_stack **head_b);
int		rrr(t_stack **head_a, t_stack **head_b);

//debugs_and_utils
t_stack	*ft_stklast(t_stack *head);
t_stack	*ft_stk_semi_last(t_stack *head);
t_stack	*ft_stknew(int nb);
int		ft_stkadd_back(t_stack **head, t_stack *node);
void	ft_stkdel(t_stack *head);
int		populate_stack(t_stack **stack_a, t_stack **stack_b, int argc, char *argv[]);
void	print_stack(t_stack *head_a, t_stack *head_b);
size_t		ft_stklen(t_stack *head);
int		real_zero(char *s);

#endif