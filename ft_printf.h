#include <unistd.h>
#include <stdarg.h>

/**
 * 1文字を出力する関数
 */
static int ft_putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * 文字列を出力する関数
 */
static int ft_putstr(char *str)
{
	int i = 0;

	if (!str)
		return ft_putstr("(null)");
	while (str[i])
		ft_putchar(str[i++]);
	return i;
}

/**
 * 数値を指定された基数で出力する関数
 */
static int ft_putnbr_base(unsigned long long n, int base, int uppercase)
{
	int count = 0;
	char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n >= (unsigned long long)base)
		count += ft_putnbr_base(n / base, base, uppercase);
	count += ft_putchar(digits[n % base]);
	return count;
}

/**
 * 符号付き整数を出力する関数
 */
static int ft_putnbr(int n)
{
	int count = 0;

	if (n == -2147483648)
		return ft_putstr("-2147483648");
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	return count + ft_putnbr_base(n, 10, 0);
}

/**
 * printf関数の再実装
 */
int ft_printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);
				count += ft_putstr("0x");
				count += ft_putnbr_base((unsigned long)ptr, 16, 0);
			}
			else if (*format == 'd' || *format == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				count += ft_putnbr_base(va_arg(args, unsigned int), 10, 0);
			else if (*format == 'x')
				count += ft_putnbr_base(va_arg(args, unsigned int), 16, 0);
			else if (*format == 'X')
				count += ft_putnbr_base(va_arg(args, unsigned int), 16, 1);
			else if (*format == '%')
				count += ft_putchar('%');
			else
			{
				// 未知のフォーマット指定子の処理
				count += ft_putchar('%');
				count += ft_putchar(*format);
			}
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return count;
}
