/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_step.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:15:12 by rvinnie           #+#    #+#             */
/*   Updated: 2021/02/23 15:15:14 by rvinnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// 0 forward
// 1 back
// 3 left
// 2 right

void	horizontal_handler(double *x_diff, double *y_diff, double fov_angle, int side)
{
	double	diff_angle;

	if (fov_angle > M_PI)
		diff_angle = fabs(fov_angle - 3 * M_PI / 2);
	else
		diff_angle = fabs(fov_angle - M_PI / 2);
	if (side == 2)
		diff_angle += M_PI / 2;
	else if (side == 3)
		diff_angle -= M_PI / 2;
	*x_diff = PLAYER_STEP * positive_sin(diff_angle);
	*y_diff = PLAYER_STEP * positive_cos(diff_angle);
	if (fov_angle >= 0 && fov_angle <= M_PI)
		*y_diff *= -1;
	if (fov_angle >= M_PI / 2 && fov_angle <= 3 * M_PI / 2)
		*x_diff *= -1;
}

void	vertical_handler(double *x_diff, double *y_diff, double fov_angle, int side)
{
	double	diff_angle;

	if (fov_angle > M_PI / 2 && fov_angle < 3 * M_PI / 2)
		diff_angle = fabs(fov_angle - M_PI);
	else
		diff_angle = fov_angle;
	if (side == 2)
		diff_angle += M_PI / 2;
	else if (side == 3)
		diff_angle -= M_PI / 2;
	*x_diff = PLAYER_STEP * positive_cos(diff_angle);
	*y_diff = PLAYER_STEP * positive_sin(diff_angle);
	if (fov_angle >= 0 && fov_angle <= M_PI)
		*y_diff *= -1;
	if (fov_angle >= M_PI / 2 && fov_angle <= 3 * M_PI / 2)
		*x_diff *= -1;
}

void	make_step(t_map *s_map, double *x_pos, double *y_pos, int side)
{
	double	fov_angle;
	double	x_diff;
	double	y_diff;
	int		check_wall_x;
	int		check_wall_y;
	char	**map;

	fov_angle = s_map->s_ray->fov_angle;
	if ((fov_angle >= M_PI / 4 && fov_angle <= 3 * M_PI / 4) || (fov_angle >= 5 * M_PI / 4 && fov_angle <= 7 * M_PI / 4))
		horizontal_handler(&x_diff, &y_diff, fov_angle, side);
	else
		vertical_handler(&x_diff, &y_diff, fov_angle, side);
	// if (alpha >= M_PI / 2 && alpha <= 3 * M_PI / 2)
	// 	x_diff *= -1;
	if (side == 1)
	{
		x_diff *= -1;
		y_diff *= -1;
	}
	map = s_map->map;
	check_wall_x = (*x_pos + x_diff) / PXL_SIZE;
	check_wall_y = (*y_pos + y_diff) / PXL_SIZE;
	// printf("%d, %d\n", check_wall_x, check_wall_y);
	// printf("%c\n", map[(int)*y_pos / PXL_SIZE][check_wall_x]);
	if (map[(int)*y_pos / PXL_SIZE][check_wall_x] != '1')
	{
		*x_pos += x_diff;
	}
	if (map[check_wall_y][(int)*x_pos / PXL_SIZE] != '1')
	{
		*y_pos += y_diff;
	}
	// if (map[check_wall_y][check_wall_x] != '1')
	// {
	// 	*x_pos += x_diff;
	// 	*y_pos += y_diff;
	// }
	// *x_pos += x_diff;
	// *y_pos += y_diff;

}

// void	side_step(t_ray *s_ray, double *x_pos, double *y_pos, int left)
// {
// 	double	fov_angle;
// 	double	x_diff;
// 	double	y_diff;

// 	fov_angle = s_ray->fov_angle;
// 	if ((fov_angle >= M_PI / 4 && fov_angle <= 3 * M_PI / 4) || (fov_angle >= 5 * M_PI / 4 && fov_angle <= 7 * M_PI / 4))
// 		horizontal_handler(&x_diff, &y_diff, s_ray->fov_angle);
// 	else
// 		vertical_handler(&x_diff, &y_diff, s_ray->fov_angle);
// 	// if (alpha >= M_PI / 2 && alpha <= 3 * M_PI / 2)
// 	// 	x_diff *= -1;
// 	*x_pos -= x_diff;
// 	*y_pos -= y_diff;
// }