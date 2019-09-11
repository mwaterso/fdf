/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   view.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/12 18:13:11 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 17:57:47 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	view1(t_input *inputs)
{
	inputs->view = 1;
	inputs->vecx.x = 20 * inputs->zoom;
	inputs->vecx.y = 0;
	inputs->vecz.x = 0;
	inputs->vecz.y = 0;
	inputs->vecy.x = 0;
	inputs->vecy.y = 20 * inputs->zoom;
}

void	view2(t_input *inputs)
{
	inputs->view = 2;
	inputs->vecx.x = 20 * inputs->zoom;
	inputs->vecx.y = 0;
	inputs->vecz.x = 0;
	inputs->vecz.y = -20 * inputs->zoom;
	inputs->vecy.x = 0;
	inputs->vecy.y = 0;
}

void	view3(t_input *inputs)
{
	inputs->view = 3;
	inputs->vecx.x = 20 * inputs->zoom;
	inputs->vecx.y = 20 * inputs->zoom;
	inputs->vecz.x = 0;
	inputs->vecz.y = -5 * inputs->zoom;
	inputs->vecy.x = -20 * inputs->zoom;
	inputs->vecy.y = 20 * inputs->zoom;
}

void	zoom(t_input *inputs, int way)
{
	inputs->zoom += (double)(way) * (0.01 * inputs->zoom);
	if (inputs->view == 1)
		view1(inputs);
	else if (inputs->view == 2)
		view2(inputs);
	else if (inputs->view == 3)
		view3(inputs);
}

int		destroywin(t_input *inputs)
{
	mlx_destroy_window(inputs->mlx_ad, inputs->win_ad);
	exit(EXIT_SUCCESS);
	return (-1);
}
