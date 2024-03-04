/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_ptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 17:54:22 by lbartels      #+#    #+#                 */
/*   Updated: 2023/11/07 15:33:03 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_length(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static void	ft_ptr(unsigned long long ptr)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (ptr >= 16)
	{
		ft_ptr(ptr / 16);
		ft_ptr(ptr % 16);
	}
	else if (ptr < 16)
		write (1, &hexa[ptr], 1);
}

int	ft_put_ptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += write (1, "(nil)", 5);
		return (len);
	}
	len += write (1, "0x", 2);
	ft_ptr(ptr);
	len += ptr_length(ptr);
	return (len);
}
