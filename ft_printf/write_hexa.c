/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:51:21 by amatta            #+#    #+#             */
/*   Updated: 2023/05/02 15:02:13 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_hexa(unsigned long n, char *hexa)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += write_hexa(n / 16, hexa);
	i += write_char(hexa[n % 16]);
	return (i);
}
