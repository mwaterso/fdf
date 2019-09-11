/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 15:27:01 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 23:07:06 by mwaterso    ###    #+. /#+    ###.fr     */
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

void	print_line(t_input *input, t_dot a, t_dot c, int color)
{
	double		dx;
	double		dy;
	int			tall;
	int			i;
	t_dot		b;

	i = 0;
	if (c.x == a.x && c.y == a.y)
		return ;
	tall = tallnomin(a.y - c.y, a.x - c.x);
	dx = (double)(a.x - c.x) / tall;
	dy = (double)(a.y - c.y) / tall;
	while (i < tall)
	{
		b.x = (c.x + i * dx);
		b.y = (c.y + i * dy);
		if (b.x >= 0 && b.x < input->win_h &&
		b.y >= 0 && b.y < input->win_w)
			input->im.tab[(int)(b.x + b.y
	* input->win_h)] = color;
		i++;
	}
}

void	free_input(t_input *inputs)
{
	int i;

	if (inputs->tab_int)
	{
		i = -1;
		while (++i < inputs->ymax && inputs->tab_int[i])
		{
			free(inputs->tab_int[i]);
		}
		free(inputs->tab_int);
	}
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
