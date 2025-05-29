/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:52:58 by shunwata          #+#    #+#             */
/*   Updated: 2025/05/29 20:57:50 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_format(va_list args, char format)
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

// // 後で消す
// #include <stdio.h>
// int	main(void)
// {
// 	int	char_count1;
// 	int	char_count2;
// 	int	dummy;
// 	dummy = 0;

// 	//ft_printf
// 	char_count1 = ft_printf("Hello %s, %c, %d, %u, %x, %X, %p, %%, %i\n", "World", '!', 123, 456, 789, 1011, &dummy, 123);
// 	ft_printf("char_count1: %d\n", char_count1);

// 	//printf
// 	char_count2 = printf("Hello %s, %c, %d, %u, %x, %X, %p, %%, %i\n", "World", '!', 123, 456, 789, 1011, &dummy, 123);
// 	printf("char_count2: %d\n", char_count2);

// 	return (0);
// }
