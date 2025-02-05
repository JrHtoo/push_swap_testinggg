/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:10:58 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/05 13:50:31 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b)->next)
	{
		if ((*stack_b)->content < (*stack_b)->next->content)
			swap_b(stack_b);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}

static void	sort_three(t_list **stack_a, t_list **stack_b)
{
	int		largest;
	bool	rotate;

	rotate = false;
	if ((*stack_b))
	{
		largest = ft_largest_position(*stack_b, 3);
		if (largest == 1)
			swap_b(stack_b);
		else if (largest == 2)
		{
			rotate_b(stack_b);
			swap_b(stack_b);
			rotate = true;
		}
		push_a(stack_a, stack_b);
		if (rotate)
			reverse_rotate_b(stack_b);
		sort_two(stack_a, stack_b);
	}
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	loop;

	i = 0;
	loop = ft_largest_position(*stack_b, 4);
	while (i < loop)
	{
		if (i == (loop - 1))
			swap_b(stack_b);
		else
			rotate_b(stack_b);
		i++;
	}
	push_a(stack_a, stack_b);
	i = 1;
	while (i++ < loop)
		reverse_rotate_b(stack_b);
	sort_three(stack_a, stack_b);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		l;
	bool	push;

	i = 0;
	l = ft_largest_index(*stack_b, 5);
	push = false;
	while (i < 4)
	{
		if ((*stack_b)->index == l - 1)
			swap_b(stack_b);
		if ((*stack_b)->index == l)
		{
			push_a(stack_a, stack_b);
			push = true;
		}
		if (push)
			if ((*stack_a)->index == l && (*stack_b)->index == l - 1)
				break ;
		rotate_b(stack_b);
		i++;
	}
	push_a(stack_a, stack_b);
	while (i--)
		reverse_rotate_b(stack_b);
	sort_three(stack_a, stack_b);
}

void	tiny_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 1)
		push_a(stack_a, stack_b);
	else if (size == 2)
		sort_two(stack_a, stack_b);
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
}
