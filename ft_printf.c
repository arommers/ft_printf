/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 10:47:47 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/13 14:19:14 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	va_list		ap;
	int			count;
	int			i;

	count = 0;
	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] != '%')
			count = count + ft_write(s[i]);//&& ft_strchr("cspdiuxX%", s[i + 1]))
		else
		{
			count = count + ft_format_spec(ap, s[i + 1]);
			i++;
		}
		i++;
	}
	va_end(ap);
	printf("print count: %d\n", count);
	return (count);
}

int	main(void)
{
	// ft_printf("print percent: %%\n", '%');
	// printf("print percent: %%\n");
	// return (0);
	char	*str;
	char	*ptr;

	str = "Bulbasaur";
	ptr = str;
	ft_printf("where? @ %p\n", ptr);
	printf("where? @ %p\n", ptr);
//
	// char	*str;

	// str = "general kenobi";
	// ft_printf("hello there:\n%s\n", str);
	// char	c;

	// c = 'c';
	// ft_printf("extra letter?\n%c\n", c);
	//int	i;

	// i = -2147483648;
	// ft_printf("my number = %d\n", i);
	// unsigned int	i;

	// i = 4437;
	// ft_printf("My unsigned int :%u\n", i);
	// return (0);

	unsigned int	i = 53146316;
	ft_printf("My hex: %x\n", i);
	printf("My hex: %x\n", i);
	return (0);
}
