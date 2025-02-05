/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:40:59 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/05 15:07:13 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	select_pivot(t_list **stack, int size)
{
	int		i;
	int		sum;
	t_list	*tmp;

	i = 0;
	sum = 1;
	tmp = (*stack);
	while (i < size && tmp)
	{
		sum += tmp->index;
		tmp = tmp->next;
		i++;
	}
	tmp = (*stack);
	while (tmp->next && tmp->index != (sum / i))
		tmp = tmp->next;
	return (tmp->content);
}

void	partition_a(t_list **stack_a, t_list **stack_b,
	t_data *data, int size)
{
	int	i;

	i = 0;
	data->pivot = select_pivot(stack_a, size);
	data->size = 0;
	data->nmoves = 0;
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

static void	partition_b(t_list **stack_a, t_list **stack_b,
	t_data *data, int size)
{
	int	i;

	i = 0;
	while (i++ < size && (*stack_b))
	{
		if ((*stack_b)->content >= data->pivot)
		{
			push_a(stack_a, stack_b);
			data->nmoves++;
			if ((*stack_a)->content == data->pivot)
				rotate_a(stack_a);
		}
		else
		{
			rotate_b(stack_b);
			data->size++;
		}
	}
	i = data->size;
	while (i--)
		reverse_rotate_b(stack_b);
	reverse_rotate_a(stack_a);
}

void	partition(t_list **stack_a, t_list **stack_b, t_data *data, int size)
{
	data->pivot = select_pivot(stack_b, size);
	data->size = 0;
	data->nmoves = 0;
	if ((*stack_b))
		partition_b(stack_a, stack_b, data, size);
}
