/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/11 09:52:21 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/15 13:25:53 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ft_printf.h"

static int	hex_size(unsigned int len)
{
	int	i;

	i = 0;
	while (len > 0)
	{
		len = len / 16;
		i++;
	}
	return (i);
}

static int	ft_print_hex(unsigned int n, char *s)
{
	char			*str;
	int				count;
	unsigned int	i;

	count = hex_size(n);
	str = (char *)ft_calloc(sizeof(char), (count + 1));
	if (!str)
		return (0);
	while (count--)
	{
		str[count] = s[n % 16];
		n = n / 16;
	}
	ft_print_str(str);
	i = ft_strlen(str);
	free(str);
	return (i);
}

int	ft_return_hex(unsigned int n, char *s)
{
	if (n == 0)
		return (ft_write_char('0'));
	else
		ft_print_hex(n, s);
	return (hex_size(n));
}
