/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 15:52:04 by lbartels      #+#    #+#                 */
/*   Updated: 2023/11/07 16:11:41 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putint(int n);
int		ft_put_unsigned(unsigned int n);
int		ft_put_hex(unsigned int hex, char format);
int		ft_put_ptr(unsigned long long ptr);
int		ft_valid_format(char c);
int		ft_print_format(va_list ptr, char format);
int		ft_printf(const char *s, ...);

#endif