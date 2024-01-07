/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:21:31 by amatta            #+#    #+#             */
/*   Updated: 2023/05/02 15:25:19 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_pointer(unsigned long n, char *hexa)
{
	int	i;

	i = 2;
	write_char('0');
	write_char('x');
	i += write_hexa(n, hexa);
	return (i);
}
