/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:22:35 by thguimar          #+#    #+#             */
/*   Updated: 2024/02/19 17:22:59 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_errors(t_stack **a, char **mat)
{
	free_stack(a);
	ft_frees(mat);
	ft_printf("Error\n");
	exit(1);
}
