/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:01:27 by jgo               #+#    #+#             */
/*   Updated: 2022/11/06 14:42:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_x(va_list *ap, const char conversion)
{
	const unsigned int	arg = va_arg(*ap, unsigned int);
	int					rv;
	char				*str;

	if (conversion == HEXA_LOWER)
		str = ft_itoa_base(arg, BASE_HEXA_LOWER);
	else
		str = ft_itoa_base(arg, BASE_HEXA_UPPER);
	if (!str)
		return (-1);
	rv = ft_putstr(str);
	free(str);
	return (rv);
}
