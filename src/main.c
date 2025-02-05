/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:07 by juhtoo-h          #+#    #+#             */
/*   Updated: 2025/02/05 13:52:24 by juhtoo-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	// t_list	*temp;

	if (argc == 1)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	if (!ft_parsing(stack_a, argc, argv))
		exit(EXIT_SUCCESS);
	if (check_sorted(stack_a, ft_lstsize(*stack_a)))
		exit(EXIT_SUCCESS);
	if (ft_lstsize(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		main_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}

	// temp = *stack_a;
	// ft_printf("number     index     current_pos\n");
	// while (temp)
	// {
	// 	ft_printf("%d            %d            %d\n", temp->content, temp->index, temp->current_pos);
	// 	temp = temp->next;
	// }
	// temp = *stack_b;
	// ft_printf("number     index     current_pos\n");
	// while (temp)
	// {
	// 	ft_printf("%d            %d            %d\n", temp->content, temp->index, temp->current_pos);
	// 	temp = temp->next;
	// }	