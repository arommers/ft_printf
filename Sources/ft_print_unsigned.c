/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unsigned.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/13 12:11:57 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/15 09:25:24 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

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

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*str;
	int				count;

	count = nbr_size(n);
	str = (char *)ft_calloc (sizeof(char), (count + 1));
	if (!str)
		return (NULL);
	while (count--)
	{
		str[count] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*str;
	int		count;

	count = 0;
	if (n == 0)
		count = count + ft_write_char('0');
	else
	{
		str = ft_unsigned_itoa(n);
		count = ft_strlen(str);
		ft_print_str(str);
		free(str);
	}
	return (count);
}
