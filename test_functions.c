// int	ft_print_int(int n)
// {
// 	int	count;

// 	count = 0;
// 	if (n == -2147483648)
// 	{
// 		write (1, "-2147483648", 11);
// 		return (count = 11);
// 	}
// 	if (n < 0)
// 	{
// 		write(1, "-", 1);
// 		n = n * -1;
// 	}
// 	if (n > 9)
// 	{
// 		ft_print_int(n / 10);
// 		ft_print_int(n % 10);
// 	}
// 	if (n >= 0 && n <= 9)
// 	{
// 		n = n + '0';
// 		write(1, &n, 1);
// 		count++;
// 	}
// 	return (count);
// }

// int	ft_print_unsint(unsigned int n)
// {
// 	char	*str;
// 	int		count;

// 	str = ft_itoa(n);
// 	count = ft_strlen(str);
// 	ft_print_str(str);
// 	free(str);
// 	return (count);
// }