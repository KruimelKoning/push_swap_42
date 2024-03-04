/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_hex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 16:57:13 by lbartels      #+#    #+#                 */
/*   Updated: 2023/11/07 15:32:55 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_length(unsigned int hex)
{
	int	len;

	len = 0;
	if (hex == 0)
		len++;
	while (hex != 0)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

int	ft_put_hex(unsigned int hex, char format)
{
	char	*hexa;
	int		len;

	len = hex_length(hex);
	if (format == 'X')
		hexa = "0123456789ABCDEF";
	if (format == 'x')
		hexa = "0123456789abcdef";
	if (hex >= 16)
	{
		ft_put_hex(hex / 16, format);
		ft_put_hex(hex % 16, format);
	}
	else if (hex < 16)
		write (1, &hexa[hex], 1);
	return (len);
}
