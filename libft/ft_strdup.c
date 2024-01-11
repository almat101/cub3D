/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:17:12 by amatta            #+#    #+#             */
/*   Updated: 2024/01/11 12:51:17 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char	*ft_strdup(const char *src)
{
	char	*dst;
	size_t	len;

	if (!src)
		return (NULL);
	len = ft_strlen(src) + 1;
	dst = malloc(len);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}
