/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:45:42 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/29 13:37:14 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_char_array(char ***array)
{
	int	i;

	if (*array == NULL)
		return ;
	i = 0;
	while ((*array)[i] != NULL)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}

void	free_int_array(int **array)
{
	if (*array == NULL)
		return ;
	free(*array);
	*array = NULL;
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (*stack == NULL)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	free_all(t_node **a, t_node **b, char **input, int *nbrs)
{
	free_stack(a);
	free_stack(b);
	free_char_array(&input);
	free_int_array(&nbrs);
}

void	err_exit(t_node **a, t_node **b, char **input, int *nbrs)
{
	free_all(a, b, input, nbrs);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
