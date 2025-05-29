/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:46:07 by shunwata          #+#    #+#             */
/*   Updated: 2025/05/29 20:50:42 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

static int	ft_putchar(char c);
static int	ft_putstr(char *str);
static int ft_putnbr_base(unsigned long long n, int base, int uppercase);
static int ft_putnbr(int n);

static int	process_format(va_list args, char format);
int ft_printf(const char *format, ...);

#endif
