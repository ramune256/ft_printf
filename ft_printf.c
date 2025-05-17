#include <unistd.h>
#include <stdarg.h>

static int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

static int	ft_putstr(char *str)
{
	int count;

	count = 0;
	if (!str)
		return ft_putstr("(null)");
	while (str[count])
		ft_putchar(str[count++]);
	return (count);
}

static int ft_putnbr_base(unsigned long long n, int base, int uppercase)
{
	char	*digits;
	int		count;

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	count = 0;
	if (n >= (unsigned long long)base)
		count += ft_putnbr_base(n / base, base, uppercase);
	count += ft_putchar(digits[n % base]);
	return (count);
}

static int ft_putnbr(int n)
{
	int count;

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
