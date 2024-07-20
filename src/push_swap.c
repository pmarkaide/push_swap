/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:35:40 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/07/20 15:16:40 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void execute_moves(t_node **a, t_node**b, int *costs)
{
    int i;
    
    i = 0;
    if(costs[0] > 0)
    {
        while(i < costs[0])
        {
            ra(a);
            i++;
        }
    }
    else
    {
        while(i < costs[0])
        {
            rra(a);
            i++;
        }
    }
    i = 0;
    if(costs[1] > 0)
    {
        while(i < costs[0])
        {
            rb(b);
            i++;
        }
    }
    else
    {
        while(i < costs[0])
        {
            rrb(b);
            i++;
        }
    }
    pb(a, b);
}

t_node *best_node_on_b(t_node **b, int nbr)
{
    int i;
    int len;
    t_node *tmp;

    i = 0;
    len = stack_len(b);
    tmp = *b;
    while(i < len)
    {
        if(tmp->nbr < nbr)
            return (tmp);
        tmp = tmp->next;
        i++;
    }
    return (tmp);
}

int *calculate_costs(t_node **a, t_node **b, t_node *node)
{

    int *costs;
    t_node *best_node;

    costs = (int *)malloc(sizeof(int) * 2);
    if (!costs)
        exit_on_error(); 
    best_node = best_node_on_b(b, node->nbr);
    costs[0] = distance_to_top(a, node);
    costs[1] = distance_to_top(b, best_node);
    return (costs);
}

void turksort(t_node **a, t_node **b)
{
    int len;
    int i;
    //t_node *tmp;
    //int dist = 0;
    int *costs;

    len = stack_len(a);
    i = 0;
    
    pb(a, b);
    pb(a, b);
    pb(a, b);
    sort_three(b);
    sb(b);
    rrb(b);
    print_list(a);
    print_list(b);
    //tmp = *a;
    while(i < len && len > 3 && a != NULL)
    {
        costs = calculate_costs(a, b, (*a));
        ft_printf("nbr = %d\tcosts[%d,%d]\n", (*a)->nbr, costs[0], costs[1]);
        execute_moves(a, b, costs);
        pa(a, b);
        i++;  
    }
    print_list(a);
    print_list(b);
}


void sort_three(t_node **head)
{
    t_node *tmp;
    t_node *highest;

    tmp = *head;
    highest = find_highest(head);
    if(tmp->nbr == highest->nbr)
        ra(head);
    else if(tmp->next->nbr == highest->nbr)
        rra(head);
    if((*head)->nbr > (*head)->next->nbr)
        sa(head);
}

void push_swap(t_node **a, t_node **b)
{
    if(is_sorted(a) || stack_len(a) == 1)
        exit(1);
    if(stack_len(a) == 2)
    {
        if((*a)->nbr > (*a)->next->nbr)
            sa(a);
        print_list(a);
        exit(1);
    }
    if(stack_len(a) == 3)
    {
        sort_three(a);
        print_list(a);
        exit(1);
    }
    turksort(a, b);
}