/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 10:47:47 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/14 11:44:02 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*c = va_arg(args, int)
s = va_arg(args, char *)
d = va_arg(args, int)
i = va_arg(args, int)
u = va_arg(args, unsigned int)
p = va_arg(args, unsigned long)# or 
                               #(unsigned long)va_arg(args, void *);
x = va_arg(args, unsigned int)
X = va_arg(args, unsigned int)
*/

int	ft_converter(va_list ap, const char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count = count + ft_write_char(va_arg(ap, int));
	else if (s == 's')
		count = count + ft_print_str(va_arg(ap, char *));
	else if (s == 'd' || s == 'i')
		count = count + ft_print_int(va_arg(ap, int));
	else if (s == 'u')
		count = count + ft_print_unsigned(va_arg(ap, unsigned int));
	else if (s == 'x')
		count = count + ft_print_hex(va_arg(ap, unsigned int),
				"0123456789abcdef");
	else if (s == 'X')
		count = count + ft_print_hex(va_arg(ap, unsigned int),
				"0123456789ABCDEF");
	if (s == 'p')
		count = count + ft_print_ptr(va_arg(ap, unsigned long),
				"0123456789abcdef");
	else if (s == '%')
		count = (count + 1)ft_write_char('%');
	return (count);
}

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
		if (s[i] == '%')
			count = count + ft_converter(ap, s[i + 1]);
			// && ft_strchr("cspdiuxX%", s[i + 1]))
			i++;
		else
			count = count + ft_write_char(s[i]);
		i++;
	}
	va_end(ap);
	printf("print count: %d\n", count);
	return (count);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*ptr;

// 	str = "Bulbasaur";
// 	ptr = str;
// 	ft_printf("where? @ %p\n", ptr);
// 	printf("where? @ %p\n", ptr);
// 	return (0);
// }

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

	// ft_printf("print percent: %%\n", '%');
	// printf("print percent: %%\n");

	// ft_printf("My hex: %x\n", i);
	// printf("My hex: %x\n", i);