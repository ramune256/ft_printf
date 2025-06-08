/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:52:23 by shunwata          #+#    #+#             */
/*   Updated: 2025/06/08 21:51:55 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[count])
		ft_putchar(str[count++]);
	return (count);
}

int	ft_putnbr_base(unsigned long long n, int base, int uppercase)
{
	char	*digits;
	int		count;

	if (uppercase)
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	count = 0;
	if (n >= (unsigned long long)base)
		count += ft_putnbr_base(n / base, base, uppercase);
	count += ft_putchar(digits[n % base]);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	return (count + ft_putnbr_base(n, 10, 0));
}

int	put_pointer(void *ptr)
{
	int count;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putnbr_base((unsigned long)ptr, 16, 0);
	return count;
}
