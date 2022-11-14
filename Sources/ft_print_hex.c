/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 09:52:21 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/14 08:53:15 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	hex_size(unsigned int len)
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

int	ft_print_hex(unsigned int n, char *s)
{
	char			*str;
	int				count;
	unsigned int	i;

	count = hex_size(n);
	str = (char *)ft_calloc(sizeof(char), (count));
	if (!str)
		return (0);
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (count--)
	{
		str[count -1] = s[n % 16];
		n = n / 16;
	}
	ft_print_str(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}
