/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_format_spec.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:19:27 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/13 13:44:50 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_format_spec(va_list ap, const char s)
{
	int	count;

	count = 0;
	// if (s == 'c')
	// 	count = count + ft_write(va_arg(ap, int));
	// else if (s == 's')
	// 	count = count + ft_print_str(va_arg(ap, char *));
	// else if (s == 'd' || s == 'i')
	// 	count = count + ft_print_int(va_arg(ap, int));
	// else if (s == 'u')
	// 	count = count + ft_print_unsint(va_arg(ap, unsigned int));
	if (s == 'x')
		count = count + ft_print_hex(va_arg(ap, unsigned int),
				"0123456789abcdef");
	else if (s == 'X')
		count = count + ft_print_hex(va_arg(ap, unsigned int),
				"0123456789ABCDEF");
	else if (s == 'p')
		count = count + ft_print_ptr(va_arg(ap, unsigned long),
				"0123456789abcdef");
	// if (s == '%')
	// 	count = count + ft_print_perc(va_arg(ap, int));
	return(count);
}
