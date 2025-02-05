/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:10:11 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/05 15:15:29 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	// t_list *temp;
	if (size <= 5 && (*stack_b))
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

// static void	quick_sort_counter(t_list **stack_a, t_list **stack_b,
// 	t_data data, int size)
// {
// 	if (size <= 5 && (*stack_b))
// 	{
// 		tiny_sort(stack_a, stack_b, size);
// 		return ;
// 	}
// 	if (!(*stack_b))
// 		return ;
// 	partition_counter(stack_a, stack_b, &data, size);
// 	push_back_to_b(stack_a, stack_b, data.nmoves);
// 	quick_sort(stack_a, stack_b, data, data.nmoves);
// 	quick_sort_counter(stack_a, stack_b, data, size - data.nmoves);
// }

void	main_sort(t_list **stack_a, t_list **stack_b)
{
	t_data	data;

	data.first_time = false;
	partition_a(stack_a, stack_b, &data, ft_lstsize(*stack_a));
	data.first_time = true;
	quick_sort(stack_a, stack_b, data, ft_lstsize(*stack_b));
	while ((*stack_b))
		push_a(stack_a, stack_b);
}

// printf("\n\nAfter Partition %d %d\n\n", data.nmoves, size - data.nmoves);
// 	temp = *stack_a;
// 	ft_printf("number     index     current_pos\n");
// 	while (temp)
// 	{
// 		ft_printf("%d            %d            %d\n", temp->content, temp->index, temp->current_pos);
// 		temp = temp->next;
// 	}
// 	temp = *stack_b;
// 	ft_printf("number     index     current_pos\n");
// 	while (temp)
// 	{
// 		ft_printf("%d            %d            %d\n", temp->content, temp->index, temp->current_pos);
// 		temp = temp->next;
// 	}	
// 	printf("\n\n");