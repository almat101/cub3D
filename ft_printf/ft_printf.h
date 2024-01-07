/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:41:17 by amatta            #+#    #+#             */
/*   Updated: 2023/05/04 15:08:20 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	handle_case(va_list args, const char c);
int	write_char(int c);
int	write_str(char *str);
int	write_hexa(unsigned long n, char *hexa);
int	write_nbr(int n);
int	write_pointer(unsigned long n, char *hexa);
int	write_unsigned(unsigned int n);
#endif
