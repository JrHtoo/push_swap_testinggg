/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:44:58 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/03 15:54:22 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_partition(t_list **stack, t_data *data, int size)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = (*stack);
	data->pivot = select_pivot(stack, size);
	while (i++ < size && temp->content > data->pivot)
	{
		if (temp->content == data->pivot)
			break ;
		temp = temp->next;
	}
	temp = temp->next;
	while (i++ < size && temp->content < data->pivot)
		temp = temp->next;
	i = data->size;
	if (i == size -1)
		return (1);
	return (0);
}
