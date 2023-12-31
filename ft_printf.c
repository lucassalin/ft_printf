/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:45:24 by lsalin            #+#    #+#             */
/*   Updated: 2022/08/31 15:11:25 by lsalin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_checker(const char *str, va_list args, int *i)
{
	if (str[0] == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (str[0] == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (str[0] == 'p')
		ft_ptr(va_arg(args, void *), i);
	else if (str[0] == 'd' || str[0] == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if (str[0] == 'u')
		ft_unsigned_putnbr(va_arg(args, unsigned int), i);
	else if (str[0] == 'x')
		ft_hexa(va_arg(args, unsigned int), "0123456789abcdef", i);
	else if (str[0] == 'X')
		ft_hexa(va_arg(args, unsigned int), "0123456789ABCDEF", i);
	else if (str[0] == '%')
		ft_putchar('%', i);
	else
		return ;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
	va_list	args;

	if (!str)
		return (0);
	i = 0;
	j = 0;
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			j += 1;
			if (!str[j])
				break ;
			ft_printf_checker(&str[j], args, &i);
		}
		else
			ft_putchar(str[j], &i);
		j++;
	}
	va_end(args);
	return (i);
}
