/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_addinttab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 20:16:36 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/25 12:36:11 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		**ft_addinttab(int **tab, int *line, size_t length)
{
	int		**newtab;
	size_t	i;

	newtab = (int **)malloc(sizeof(int *) * (length + 1));
	i = 0;
	while (i < length)
	{
		newtab[i] = tab[i];
		free(&(tab[i]));
		tab[i] = NULL;
		i++;
	}
	free(&tab);
	newtab[i] = line;
	free(&line);
	line = NULL;
	return (newtab);
}
