/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_ptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 15:06:24 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/14 08:54:34 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	hex_size(unsigned long int len)
{
	unsigned long int	i;

	i = 0;
	while (len > 0)
	{
		len = len / 10;
		i++;
	}
	return (i);
}

int	ft_print_ptr(unsigned long n, char *s)
{
	char			*str;
	int				count;
	unsigned long	i;

	count = hex_size(i);
	str = (char *)ft_calloc (sizeof(char), (count));
	if (!str)
		return (0);
	write(1, "0x", 2);
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (count--)
	{
		str[count -1] = s[i % 16];
		i = i / 16;
	}
	ft_print_str(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}
