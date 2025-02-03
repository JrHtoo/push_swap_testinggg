/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:40:59 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/03 15:38:39 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// static void	get_pivot_position(t_list **stack_a, t_data *data)
// {
// 	t_list	*temp;

// 	temp = *stack_a;
// 	while (temp)
// 	{
// 		if (temp->content == data->pivot)
// 		{
// 			data->pivot_position = temp->current_pos;
// 			break ;
// 		}
// 		temp = temp->next;
// 	}
// }

// static void	push_pivot(t_list **stack_a, t_list **stack_b, t_data *data)
// {
// 	int	i;

// 	i = data->size;
// 	get_pivot_position(stack_a, data);
// 	if (data->pivot_position < ft_lstsize(*stack_a) / 2)
// 	{
// 		while ((*stack_a)->content != data->pivot)
// 		{
// 			rotate_a(stack_a);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while ((*stack_a)->content != data->pivot)
// 		{
// 			i--;
// 			reverse_rotate_a(stack_a);
// 		}
// 	}
// 	push_b(stack_a, stack_b);
// 	while (i-- > 0)
// 		reverse_rotate_a(stack_a);
// }

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

static void	partition_b(t_list **stack_a, t_list **stack_b,
	t_data *data, int size)
{
	int			i;

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
