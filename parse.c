/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/06/04 17:52:36 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 21:31:42 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int				return_error(char **tmp_tab, t_input *map)
{
	ft_putendl("Error");
	ft_2dstrdel(&tmp_tab);
	free_input(map);
	if (map->mlx_ad && map->win_ad)
		mlx_destroy_window(map->mlx_ad, map->win_ad);
	exit(0);
}

static void		check_line(t_input *map)
{
	int		ret;
	int		i;
	char	*line;

	i = 0;
	while ((ret = get_next_line(map->fd2, &line)) == 1)
	{
		map->len_y++;
		while (++i < ft_strlen(line))
			if (!ft_isascii(line[i]))
				exit(0);
		ft_strdel(&line);
	}
	if (ret == -1)
	{
		ft_putendl("Fdf need a file as argument");
		exit(0);
	}
}

int				intab_int(t_input *map, char **tmp_tab, t_index index)
{
	if (!(map->tab_int[index.i] = (int *)malloc(sizeof(int) * map->len_x)))
		return (-1);
	while (index.j < map->len_x)
	{
		map->tab_int[index.i][index.j] = ft_atoi(tmp_tab[index.j]);
		if (map->max_val < map->tab_int[index.i][index.j])
			map->max_val = map->tab_int[index.i][index.j];
		index.j++;
	}
	ft_2dstrdel(&tmp_tab);
	return (0);
}

int				fill_tab_int(t_input *map)
{
	char		**tmp_tab;
	t_index		index;
	char		*line;

	index = (t_index){.i = 0, .j = 0};
	while (get_next_line(map->fd, &line))
	{
		tmp_tab = ft_strsplit(line, ' ');
		if (index.i == 0)
		{
			map->len_x = ft_tablen((void **)tmp_tab);
			if (!(map->tab_int = (int **)malloc(sizeof(int *) * map->len_y)))
				return (-1);
		}
		if (map->len_x != ft_tablen((void **)tmp_tab))
			return_error(tmp_tab, map);
		if(intab_int(map, tmp_tab, index) < 0)
		{
			return_error(tmp_tab, map);
			return (-1);
		}
		ft_strdel(&line);
		index.i++;
	}
	return (0);
}

int				parse_file(t_input *map, char *file)
{
	int		ret;

	map->fd = open(file, O_RDONLY);
	map->fd2 = open(file, O_RDONLY);
	check_line(map);
	if ((ret = fill_tab_int(map)) == -1)
		return (-1);
	return (0);
}
