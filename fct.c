/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 15:27:01 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 18:28:45 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		tallnomin(int a, int b)
{
	int e;
	int r;

	e = a;
	r = b;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a >= b)
		return (a);
	return (b);
}

void	print_line(t_input *input, t_dot a, t_dot b, int color)
{
	double		dx;
	double		dy;
	int			tall;
	int			i;

	i = 0;
	if (b.x == a.x && b.y == a.y)
		return ;
	tall = tallnomin(a.y - b.y, a.x - b.x);
	dx = (double)(a.x - b.x) / tall;
	dy = (double)(a.y - b.y) / tall;
	while (!((int)(b.x + i * dx) == a.x && (int)(b.y + i * dy) == a.y))
	{
		if ((b.x + i * dx) >= 0 && (b.x + i * dx) <= input->win_h &&
		(b.y + i * dy) >= 0 && (b.y + i * dy) <= input->win_w)
			input->im.tab[(int)((int)(b.x + i * dx) + (int)(b.y + i * dy)
	* input->win_h)] = color;
		i++;
	}
}

void	free_input(t_input *inputs)
{
	int i;

	i = -1;
	while (++i < inputs->ymax && inputs->tab_int[i])
	{
		free(inputs->tab_int[i]);
	}
	free(inputs->tab_int);
}

void	calc(int y, int x, t_dot *a, t_input *data)
{
	a->x = data->tab_int[y][x] * data->vecz.x + x *
	data->vecx.x + y * data->vecy.x + data->origin.x;
	a->y = data->tab_int[y][x] * data->vecz.y + x *
	data->vecx.y + y * data->vecy.y + data->origin.y;
}

void	racc(t_input *inputs)
{
	clear_im(inputs);
	fdf(inputs);
}
