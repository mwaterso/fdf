/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/28 16:53:02 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/06/28 18:27:38 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int		var_init(t_input *inputs)
{
	inputs->win_h = 1500;
	inputs->win_w = 1000;
	inputs->mlx_ad = mlx_init();
	inputs->win_ad = mlx_new_window(inputs->mlx_ad, inputs->win_h,
	inputs->win_w, "Fdf");
	inputs->im.ad = mlx_new_image(inputs->mlx_ad, inputs->win_h, inputs->win_w);
	inputs->im.tab = (int *)mlx_get_data_addr(inputs->im.ad, &(inputs->
	im.bits_per_pixel), &(inputs->im.size_line), &(inputs->im.endian));
	inputs->color1 = 0xFF0000;
	inputs->color1 = 0x0000FF;
	inputs->zoom = 1;
	view1(inputs);
	return (1);
}

void	clear_im(t_input *data)
{
	int i;

	i = -1;
	while (++i <= data->win_h * data->win_w)
		data->im.tab[i] = 0;
}

int		keyboard(int key, t_input *inputs)
{
	if (key == KEY_1)
		view1(inputs);
	if (key == KEY_2)
		view2(inputs);
	if (key == KEY_3)
		view3(inputs);
	if (key == KEY_PAD_ADD)
		zoom(inputs, 1);
	if (key == KEY_PAD_SUB)
		zoom(inputs, -1);
	if (key == KEY_RIGHT)
		inputs->origin.x += 10;
	if (key == KEY_LEFT)
		inputs->origin.x -= 10;
	if (key == KEY_UP)
		inputs->origin.y -= 10;
	if (key == KEY_DOWN)
		inputs->origin.y += 10;
	if (key == KEY_ESCAPE)
	{
		mlx_destroy_window(inputs->mlx_ad, inputs->win_ad);
		return (1);
	}
	racc(inputs);
	return (1);
}

int		fdf(t_input *data)
{
	int		i;
	t_dot	a;
	t_dot	b;

	i = -1;
	while (++i < ((data->len_x) * (data->len_y)))
	{
		calc(i / data->len_x, i % data->len_x, &a, data);
		if ((i % data->len_x) != data->len_x - 1)
		{
			calc(i / data->len_x, i % data->len_x + 1, &b, data);
			print_line(data, a, b, 0xFFFF00);
		}
		if (i >= data->len_x)
		{
			calc(i / data->len_x - 1, i % data->len_x, &b, data);
			print_line(data, a, b, 0xFF00FF);
		}
	}
	mlx_put_image_to_window(data->mlx_ad, data->win_ad, data->im.ad, 0, 0);
	return (1);
}

int		main(int arc, char **arv)
{
	t_input input;

	input.tab_int = NULL;
	input.len_y = 0;
	if (arc != 2)
		return (1);
	if (parse_file(&input, arv[1]) < 0)
	{
		if (input.tab_int)
			free_input(&input);
		return (1);
	}
	var_init(&input);
	fdf(&input);
	mlx_hook(input.win_ad, 2, 0, &keyboard, &input);
	mlx_loop(input.mlx_ad);
	free_input(&input);
}
