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

#include "../cub3d.h"

void	put_error(t_map *s_map, char **arr, int flag, int stage)
{
	char	*str;

	free_arr(arr);
	write(2, "Error\n", 7);
	if (flag == 1)
		str = "Wrong number of arguments.\n";
	else if (flag == 2)
		str = "Unable to open file.\n";
	else if (flag == 3)
		str = "Unable to read file.\n";
	else if (flag == 4)
		str = "Unable to allocate memory.\n";
	else if (flag == 5)
		str = "Wrong map.\n";
	else if (flag == 6)
		str = "Wrong path.\n";
	else if (flag == 7)
		str = "Wrong screenshot flag.\n";
	write(2, str, ft_strlen(str));
	exit_game(s_map, stage);
}
