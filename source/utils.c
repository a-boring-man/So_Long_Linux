/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 10:09:46 by jrinna            #+#    #+#             */
/*   Updated: 2022/02/02 13:53:26 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	please_stop(void *ref)
{
	(void)ref;
	exit(0);
}

void	ft_end(t_vars *ref)
{
	printf("number of move-> %d\n", ref->player_move_count);
	exit (0);
}

void	ft_error(int n)
{
	if (n == 1)
		printf("Error\nargument number incorect");
	if (n == 2)
		printf("Error\nopening error");
	if (n == 3)
		printf("Error\nmissing wall");
	if (n == 4)
		printf("Error\nparsing error");
	if (n == 5)
		printf("Error\nmap contain illegal character");
	if (n == 6)
		printf("Error\nmap is not rectangular enough");
	if (n == 7)
		printf("Error\nmissing collectible, exit or player spot");
	if (n == 8)
		printf("Error\nnot a .ber extension");
	exit (0);
}

long	ft_strlen_s(char *str)
{
	long	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_f(char *s1, char *s2)
{
	char	*new_string;
	long	i;
	long	j;

	new_string = malloc(ft_strlen_s(s1) + ft_strlen_s(s2) + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			new_string[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new_string[j++] = s2[i++];
	new_string[j] = '\0';
	if (s1)
		free(s1);
	return (new_string);
}
