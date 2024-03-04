/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_unsigned.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 17:44:41 by lbartels      #+#    #+#                 */
/*   Updated: 2023/11/07 16:11:18 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_string(unsigned int n, int len, char *str)
{
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

static int	ft_count_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_count_len(n);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	str = ft_string(n, len, str);
	return (str);
}

int	ft_put_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_uitoa(n);
	len = ft_putstr(str);
	free (str);
	return (len);
}
