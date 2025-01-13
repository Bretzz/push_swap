/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: totommi <totommi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:19:02 by topiana-          #+#    #+#             */
/*   Updated: 2025/01/13 02:03:02 by totommi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mini_slot(t_stack *head, int nb);
int	mini_push(t_stack *head, int nb);
int	slot_ready(t_stack *head, int nb);
int	push_ready(t_stack *head, int nb);

/*applie the move 'iter' times
RETURNS: 0 all good, 1 error*/
int	cycle_move(t_stack **head_a, t_stack **head_b, int iter, int (*move)(t_stack **, t_stack **))
{
	int	i;

	i = 0;
	while (i < iter)
		i += (*move)(head_a, head_b);
	return (0);
}

/*counts the number of moves that 'best_rotator' would do*/
int	mini_rotator(t_stack *head_a, t_stack *head_b, size_t a, size_t b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_stklen(head_a);
	len_b = ft_stklen(head_b);
	if (a > (len_a / 2) && b > (len_b / 2))
	{
		if (len_a - a > len_b - b)
			return (len_a - a);
		else
			return (len_b - b);
	}
	else if (a <= (len_a / 2) && b <= (len_b / 2))
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	else if (a > (len_a / 2) && b <= (len_b / 2))
		return (len_a - a + b);
	else /* if (a <= (len_a / 2) && b > (len_b / 2)) */
		return (a + len_b - b);
}

/*takes 2 stacks and the position of the slot and the number to push
Applies the moves to set up both stack for the push optimizing the doubles
(ex: if 'ra' and 'rb' is needed performs 'rr' instead)
RETURNS: the number of moves made*/
int	best_rotator(t_stack **head_a, t_stack **head_b, size_t a, size_t b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = ft_stklen(*head_a);
	len_b = ft_stklen(*head_b);
	if (a > (len_a / 2) && b > (len_b / 2))
	{
		if (len_a - a > len_b - b)
		{
			cycle_move(head_a, head_b, len_b - b, &rrr);
			cycle_move(head_a, head_b, (len_a - a) - (len_b - b), &rra);
			return (len_a - a);
		}
		else
		{
			cycle_move(head_a, head_b, len_a - a, &rrr);
			cycle_move(head_a, head_b, (len_b - b) - (len_a - a), &rrb);
			return (len_b - b);
		}

	}
	else if (a <= (len_a / 2) && b <= (len_b / 2))
	{
		if (a > b)
		{
			cycle_move(head_a, head_b, b, &rr);
			cycle_move(head_a, head_b, a - b, &ra);
			return (a);
		}
		else
		{
			cycle_move(head_a, head_b, a, &rr);
			cycle_move(head_a, head_b, b - a, &rb);
			return (b);
		}
	}
	else if (a > (len_a / 2) && b <= (len_b / 2))
	{
		cycle_move(head_a, head_b, len_a - a, &rra);
		cycle_move(head_a, head_b, b, &rb);
		return (len_a - a + b);
	}
	else /* if (a <= (len_a / 2) && b > (len_b / 2)) */
	{
		cycle_move(head_a, head_b, a, &ra);
		cycle_move(head_a, head_b, len_b - b, &rrb);
		return (a + len_b - b);
	}
}

/*sets up 'a' to recive 'nb' from 'b'*/
int	rotate_a(t_stack **head_a, t_stack **head_b, int nb)
{
	size_t	i;
	size_t	len;
	t_stack *temp_a;

	temp_a = *head_a;
	len = ft_stklen(temp_a);
	i = mini_slot(*head_a, nb);
	if (i > (len / 2))
	{
		i = len - i;
		cycle_move(head_a, head_b, i, &rra);
	}
	else
		cycle_move(head_a, head_b, i, &ra);
	return (i);
}

/*sets up 'b' to push 'nb' to 'a'*/
int	rotate_b(t_stack **head_a, t_stack **head_b, int nb)
{
	size_t	i;
	size_t	len;
	t_stack *temp_b;

	temp_b = *head_b;
	len = ft_stklen(temp_b);
	i = mini_push(*head_b, nb);
	if (i > (len / 2))
	{
		i = len - i;
		cycle_move(head_a, head_b, i, &rrb);
	}
	else
		cycle_move(head_a, head_b, i, &rb);
	return (i);
}

/*takes stack as parameter
rotates it until the lowest number is on top
RERTURNS: the number of moves done, -1 error*/
int	low_on_top(t_stack **head_a, t_stack **head_b)
{
	int		moves;
	int		lowest;
	t_stack	*temp_a;

	temp_a = *head_a;
	lowest = temp_a->nb;
	while (temp_a)
	{
		if (temp_a->nb < lowest)
			lowest = temp_a->nb;
		temp_a = temp_a->next;
	}
	//ft_printf("lowest=%i\n", lowest);
	moves = rotate_a(head_a, head_b, lowest);
	return (moves);
}

/*takes bot the stacks and the element to push as parameters
applies the moves to push the element from 'b' to 'a'
RETURNS: the number of moves applied, -1 if error*/
int	push_it(t_stack **head_a, t_stack **head_b, int nb)
{
	int	moves;

	moves = 0;
	//moves += rotate_a(head_a, head_b, nb);
	//moves += rotate_b(head_a, head_b, nb);
	moves += best_rotator(head_a, head_b, mini_slot(*head_a, nb), mini_push(*head_b, nb));
	moves += pa(head_a, head_b);
	return (moves);
}

/*takes the 'a' stack after the 'migration' and the 'b' stack as parameters
applies 'sa' if the first number of 'a' is bigger than the second
RETURNS: 1 if it was, 0 if it wasn't*/
int	quick_a(t_stack **head_a, t_stack **head_b)
{
	if ((*head_a)->nb > (*head_a)->next->nb)
	{
		sa(head_a, head_b);
		return (1);
	}
	return (0);
}

/*takes bot the stacks as parameters
checks how many moves would it take to push each element of the
stack 'b' in the stack 'a'
RETURNS: the 'cheapest' number to move (considering there are no repetitions)*/
int	cheapest_push(t_stack *head_a, t_stack *head_b)
{
	int		temp_moves;
	int		best_moves;
	int		best;
	t_stack *temp_b;

	best = head_b->nb;
	best_moves = mini_rotator(head_a, head_b, mini_slot(head_a, best),
		mini_push(head_b, best)) + 1;
	temp_b = head_b->next;
	while (temp_b)
	{
		temp_moves = mini_rotator(head_a, head_b,
			mini_slot(head_a, temp_b->nb), mini_push(head_b, temp_b->nb)) + 1;
		if (temp_moves < best_moves)
		{
			best_moves = temp_moves;
			best = temp_b->nb;
		}
		temp_b = temp_b->next;
	}
	//ft_printf("best=%i, with %i move(s)\n", best, best_moves);
	return (best);
}

/*push_ready helperr, also useful in push_it*/
int	mini_push(t_stack *head, int nb)
{
	int	i;

	i = 0;
	while (head && head->nb != nb)
	{
		head = head->next;
		i++;
	}
	return (i);
}

/*takes a head pointer and a number as parameter
(the number must be contained in the stack)
RETURNS: the numebr of moves it takes to get the number to the top, -1 if error*/
int	push_ready(t_stack *head, int nb)
{
	size_t	i;
	size_t	len;

	if (!head)
		return (-1);
	len = ft_stklen(head);
	i = mini_push(head, nb);
	if (i > (len / 2))
		i = len - i;
	return (i);
}

/* slot_ready helperr (also useful to rotate_a)
RETURNS: the number of moves to make the stack ready to
'recive' the number 'nb' with only 'ra'*/
int	mini_slot(t_stack *head, int nb)
{
	int	i;
	int	prev_nb;

	i = 0;
	while (head && head->nb > nb)
	{
		prev_nb = head->nb;
		head = head->next;
		i++;
		if (head && prev_nb > head->nb)
			break ;
	}
	while (head && head->nb < nb)
	{
		prev_nb = head->nb;
		head = head->next;
		i++;
		if (head && prev_nb > head->nb)
			break ;
	}
	return (i);
}

/*takes an ordered stack (lower to higher, top to bottm, circular ok)
and a number as parameter and returns the number of moves
to make the stack ready to 'recive' the number (from a push)
RETURNS: number of moves, -1 for error*/
int	slot_ready(t_stack *head, int nb)
{
	size_t	i;
	size_t	len;

	if (!head)
		return (-1);
	len = ft_stklen(head);
	i = mini_slot(head, nb);
	if (i > (len / 2))
		i = len - i;
	return (i);
}

/*moves all the elements from 'a' to 'b' except for 2
RETURNS: the number of moves, 0 for error*/
int	migrate_to_b(t_stack **head_a, t_stack **head_b)
{
	int	moves;
	if (!*head_a)
		return (0);
	moves = 0;
	while ((*head_a)->next->next)
		moves += pb(head_a, head_b);
	return (moves);
}

int	main(int argc, char *argv[])
{
	int		moves;
	size_t	len;
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		len = ft_arrlen(args);
		if (len == 1)
			return (1);
		//ft_print_arr(args);
	}
	else
	{
		args = &argv[1];
		len = argc - 1;
	}
	if (!parse_ready(len, args))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!populate_stack(&stack_a, &stack_b, len, args))
	{
		ft_stkdel(stack_a);
		ft_stkdel(stack_b);
		return (1);
	}
	moves = 0;
	//print_stack(stack_a, stack_b);
	moves += migrate_to_b(&stack_a, &stack_b);
	//print_stack(stack_a, stack_b);
	moves += quick_a(&stack_a, &stack_b);
	//print_stack(stack_a, stack_b);
	while (stack_b)
	{
		//ft_printf("curr moves=%i\n", moves);
		moves += push_it(&stack_a, &stack_b, cheapest_push(stack_a, stack_b));
		//print_stack(stack_a, stack_b);
	}
	//ft_printf("curr moves=%i\n", moves);
	moves += low_on_top(&stack_a, &stack_b);
	//moves += rra(&stack_a, &stack_b);
	//print_stack(stack_a, stack_b);
	//ft_printf("curr moves=%i\n", moves);
	/*if (stk_issorted(stack_a))
		ft_printf("the stack is sorted!! ");
	else
		ft_printf("the stack is all messed up ");
	if (moves <= 5500)
		ft_printf("and you used less than 5500 moves!\n");
	else
		ft_printf("but you used more than 5500 moves...\n");*/
	if (argc == 2)
		ft_free_arr(args);
	ft_stkdel(stack_a);
	ft_stkdel(stack_b);
	if (moves > 5500)
		return (1);
	return (0);
}
