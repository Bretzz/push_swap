/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: topiana- <topiana-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:16:01 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 15:26:09 by topiana-         ###   ########.fr       */
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

//algoritm
int		cycle_move(t_stack **head_a, t_stack **head_b,
			int iter, int (*move)(t_stack **, t_stack **));
int		push_it(t_stack **head_a, t_stack **head_b, int nb);
int		cheapest_push(t_stack *head_a, t_stack *head_b);

int		best_rotator(t_stack **head_a, t_stack **head_b, size_t a, size_t b);
int		rra_rb(t_stack **head_a, t_stack **head_b, int a, int b);
int		ra_rrb(t_stack **head_a, t_stack **head_b, int a, int b);

int		migrate_to_b(t_stack **head_a, t_stack **head_b);
int		quick_a(t_stack **head_a, t_stack **head_b);
int		rotate_a(t_stack **head_a, t_stack **head_b, int nb);
int		low_on_top(t_stack **head_a, t_stack **head_b);

int		mini_slot(t_stack *head, int nb);
int		mini_push(t_stack *head, int nb);
int		mini_rotator(t_stack *head_a, t_stack *head_b, size_t a, size_t b);

//debugs_and_utils
t_stack	*ft_stknew(int nb);
int		ft_stkadd_back(t_stack **head, t_stack *node);
t_stack	*ft_stklast(t_stack *head);
t_stack	*ft_stk_semi_last(t_stack *head);

size_t	ft_arrlen(char **arr);
size_t	ft_stklen(t_stack *head);
void	ft_stkdel(t_stack *head);
int		populate_stack(t_stack **stack_a, t_stack **stack_b,
			int len, char **args);
int		ft_free_arr(char **arr);

void	print_stack(t_stack *head_a, t_stack *head_b);
void	ft_print_arr(char **arr);

//checkers
int		parse_ready(int argc, char **args);
int		stk_issorted(t_stack *head);

#endif