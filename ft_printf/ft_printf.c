/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:45:16 by amatta            #+#    #+#             */
/*   Updated: 2023/05/04 15:14:37 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	handle_case(va_list args, const char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += write_char(va_arg(args, int));
	else if (c == 's')
		count += write_str(va_arg(args, char *));
	else if (c == 'p')
		count += write_pointer(va_arg(args, unsigned long), "0123456789abcdef");
	else if (c == 'd' || c == 'i')
		count += write_nbr(va_arg(args, int));
	else if (c == 'u')
		count += write_unsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		count += write_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		count += write_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		count += write_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (0);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += handle_case(args, str[i]);
		}
		else
			count += write_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
