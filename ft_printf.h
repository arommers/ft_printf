/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:48:01 by arommers      #+#    #+#                 */
/*   Updated: 2022/11/13 12:04:27 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int			ft_write(int i);
int			ft_printf(const char *s, ...);
int			ft_format_spec(va_list ap, const char s);
int			ft_print_str(char *s);
int			ft_print_int(int n);
int			ft_print_unsint(unsigned int i);
int			ft_print_hex(unsigned int n, char *s);
int			ft_print_ptr(unsigned long n, char *s);
int			ft_print_perc(int n);

#endif