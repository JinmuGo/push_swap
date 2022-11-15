/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:07:10 by jgo               #+#    #+#             */
/*   Updated: 2022/11/05 14:47:17 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	cal_num_len(size_t n, const size_t base_len)
{
	size_t	len;

	len = 1;
	while (n > (base_len - 1))
	{
		n /= base_len;
		len ++;
	}
	return (len);
}

char	*ft_itoa_base(size_t n, char *base)
{
	char			*str;
	size_t			len;
	const size_t	base_len = ft_strlen(base);

	len = cal_num_len(n, base_len);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = base[n % base_len];
		n /= base_len;
		len--;
	}
	return (str);
}
