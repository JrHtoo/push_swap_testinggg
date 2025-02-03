/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:10:11 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/03 15:57:15 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	partition_a(t_list **stack_a, t_list **stack_b,
	t_data *data, int size)
{
	int			i;

	i = 0;
	while (i++ < size && (*stack_a))
	{
		if ((*stack_a)->content <= data->pivot)
		{
			push_b(stack_a, stack_b);
			data->nmoves++;
			if ((*stack_b)->content == data->pivot)
				rotate_b(stack_b);
		}
		else
		{
			rotate_a(stack_a);
			data->size++;
		}
	}
	i = data->size;
	reverse_rotate_b(stack_b);
	while ((*stack_a))
		push_b(stack_a, stack_b);
}

static void	partitionn(t_list **stack_a, t_list **stack_b, t_data *data, int size)
{
	data->pivot = select_pivot(stack_a, size);
	data->size = 0;
	data->nmoves = 0;
	if ((*stack_a))
		partition_a(stack_a, stack_b, data, size);
}

static void	push_back_to_b(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		push_b(stack_a, stack_b);
		i++;
	}
}

static void	quick_sort(t_list **stack_a, t_list **stack_b,
	t_data data, int size)
{
	if (size <= 4 && (*stack_b))
	{
		tiny_sort(stack_a, stack_b, size);
		return ;
	}
	if (!(*stack_b))
		return ;
	if (!data.first_time)
	{
		partition(stack_a, stack_b, &data, size);
		push_back_to_b(stack_a, stack_b, data.nmoves);
	}
	data.first_time = false;
	quick_sort(stack_a, stack_b, data, data.nmoves);
	quick_sort(stack_a, stack_b, data, size - data.nmoves);
}

void	main_sort(t_list **stack_a, t_list **stack_b)
{
	t_data	data;

	data.first_time = false;
	partitionn(stack_a, stack_b, &data, ft_lstsize(*stack_a));
	data.first_time = true;
	quick_sort(stack_a, stack_b, data, ft_lstsize(*stack_b));
	while ((*stack_b))
		push_a(stack_a, stack_b);
}
