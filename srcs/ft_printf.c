/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:52:58 by shunwata          #+#    #+#             */
/*   Updated: 2025/06/04 13:34:59 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_format(va_list args, char format)
{
	int		count;
	void	*ptr;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		count += ft_putstr("0x");
		count += ft_putnbr_base((unsigned long)ptr, 16, 0);
	}
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putnbr_base(va_arg(args, unsigned int), 10, 0);
	else if (format == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned int), 16, 0);
	else if (format == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned int), 16, 1);
	else if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += process_format(args, *format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
