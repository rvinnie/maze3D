/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:44:37 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/08 10:44:41 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void put_error(int flag)
{
	// don't forget to free memory
	write(1, "Error\n", 7);
	if (flag == 1)
		write(1,"Wrong number of arguments\n", 27);
	else if (flag == 2)
		write(1, "Unable to open file.\n", 22);
	else if (flag == 3)
		write(1, "Unable to read file.\n", 22);
	else if (flag == 4)
		write(1, "Unable to allocate memory.\n", 28);
	else if (flag == 5)
		write(1, "Wrong map.\n", 11);
	exit(1);
}
