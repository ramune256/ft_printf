#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	char_count1;
	int	char_count2;
	int	dummy;
	dummy = 0;

	//ft_printf
	char_count1 = ft_printf("Hello %s, %c, %d, %u, %x, %X, %p, %%, %i\n", "World", '!', 123, 456, 789, 1011, &dummy, 123);
	ft_printf("char_count1: %d\n\n", char_count1);

	//printf
	char_count2 = printf("Hello %s, %c, %d, %u, %x, %X, %p, %%, %i\n", "World", '!', 123, 456, 789, 1011, &dummy, 123);
	printf("char_count2: %d\n\n", char_count2);

	//libft
	printf("Libft test -> ft_toupper('c')\nResult -> %c\n", ft_toupper('c'));

	return (0);
}
