/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 15:35:44 by lbartels      #+#    #+#                 */
/*   Updated: 2023/11/07 15:32:35 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_valid_format(char c)
{
	char	*formats;

	formats = "cspdiuxX%";
	while (*formats)
	{
		if (c == *formats)
			return (1);
		formats++;
	}
	return (0);
}

int	ft_print_format(va_list ptr, char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len = ft_putchar(va_arg(ptr, int));
	else if (format == 's')
		len = ft_putstr(va_arg(ptr, char *));
	else if (format == 'p')
		len = ft_put_ptr(va_arg(ptr, unsigned long long));
	else if (format == 'd' || format == 'i')
		len = ft_putint(va_arg(ptr, int));
	else if (format == 'u')
		len = ft_put_unsigned(va_arg(ptr, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_put_hex(va_arg(ptr, unsigned int), format);
	else if (format == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	va_start(ptr, s);
	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == '%' && ft_valid_format(s[i + 1]))
		{
			len += ft_print_format(ptr, s[i + 1]);
			i += 2;
		}
		if (s[i])
		{
			if (s[i] != '%')
				len += ft_putchar(s[i]);
			i++;
		}
	}
	va_end(ptr);
	return (len);
}
