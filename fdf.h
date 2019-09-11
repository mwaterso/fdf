/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/06 16:39:13 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2019/09/11 22:01:28 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "keyboard.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct	s_dot
{
	int		x;
	int		y;
}				t_dot;

typedef struct	s_fdot
{
	double		x;
	double		y;
}				t_fdot;

typedef struct	s_image
{
	void	*ad;
	int		*tab;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_image;

typedef struct	s_input
{
	void		*mlx_ad;
	void		*win_ad;
	void		*button_ad;
	int			win_h;
	int			win_w;
	int			totalnb;
	int			countline;
	int			fd;
	int			fd2;
	int			**tab_int;
	int			len_y;
	int			len_x;
	int			max_val;
	int			color1;
	int			color2;
	int			view;
	double		zoom;
	double		xmax;
	double		ymax;
	double		zmax;
	t_fdot		vecx;
	t_fdot		vecy;
	t_fdot		vecz;
	t_dot		origin;
	t_image		im;
}				t_input;

typedef struct	s_index
{
	int		i;
	int		j;
}				t_index;

int				parse_file(t_input *data, char *file);
int				destroywin(t_input *inputs);
int				fdf(t_input *data);
int				return_error(char **tmp_tab, t_input *map);
void			print_line(t_input *input, t_dot a, t_dot b, int color);
void			view1(t_input *inputs);
void			view2(t_input *inputs);
void			view3(t_input *inputs);
void			zoom(t_input *inputs, int way);
void			free_input(t_input *inputs);
void			calc(int x, int y, t_dot *a, t_input *data);
void			racc(t_input *inputs);
void			clear_im(t_input *data);
#endif
