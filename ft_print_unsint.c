/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unsint.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 12:11:57 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/13 12:18:58 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static int	nbr_size(unsigned int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		len = len / 10;
		i++;
	}
	return (i);
}

char	*ft_unsi_itoa(unsigned int n)
{
	char			*str;
	int				count;
	long int		i;

	i = n;
	count = nbr_size(i);
	str = (char *)ft_calloc (sizeof(char), (count + 1));
	if (!str)
		return (NULL);
	if (i == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (count--)
	{
		str[count] = i % 10 + '0';
		i = i / 10;
	}
	return (str);
}

int	ft_print_unsint(unsigned int n)
{
	char	*str;
	int		count;

	str = ft_unsi_itoa(n);
	count = ft_strlen(str);
	ft_print_str(str);
	free(str);
	return (count);
}