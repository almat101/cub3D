/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:25:34 by amatta            #+#    #+#             */
/*   Updated: 2023/04/26 16:40:39 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_unsigned(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n > 9)
		ret += write_unsigned(n / 10);
	ret += write_char(n % 10 + 48);
	return (ret);
}
