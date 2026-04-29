/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbuscaro <lbuscaro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:25:23 by lbuscaro          #+#    #+#             */
/*   Updated: 2025/05/06 13:47:40 by lbuscaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_putarg(char format, va_list list);

int	ft_printf(const char *str, ...)
{
	va_list	list;
	size_t	ln;

	ln = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str != '%')
			ln += ft_putchar_fd(*str, 1);
		else
			ln += ft_putarg(*(++str), list);
		str++;
	}
	va_end(list);
	return (ln);
}

static int	ft_putarg(char format, va_list lst)
{
	size_t	ln;

	ln = 0;
	if (format == 'c')
		ln += ft_putchar_fd(va_arg(lst, int), 1);
	else if (format == 's')
		ln += ft_putstr_fd(va_arg(lst, char *), 1);
	else if (format == 'p')
		ln += ft_putaddr_fd(va_arg(lst, unsigned long int), 1);
	else if (format == 'd' || format == 'i')
		ln += ft_putint_fd(va_arg(lst, int), 1);
	else if (format == 'u')
		ln += ft_putuint_fd(va_arg(lst, unsigned int), "0123456789", 1);
	else if (format == 'x')
		ln += ft_putuint_fd(va_arg(lst, unsigned int), "0123456789abcdef", 1);
	else if (format == 'X')
		ln += ft_putuint_fd(va_arg(lst, unsigned int), "0123456789ABCDEF", 1);
	else if (format == '%')
		ln += ft_putchar_fd('%', 1);
	return (ln);
}
