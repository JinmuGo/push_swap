/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:46:00 by jgo               #+#    #+#             */
/*   Updated: 2022/11/05 17:39:36 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_d(va_list *ap, const char conversion)
{
	const int	arg = va_arg(*ap, int);
	const char	*str = ft_itoa(arg);
	int			iter;

	if (str && (conversion == DECIMAL || conversion == INT))
	{
		iter = ft_putstr((char *)str);
		free((void *)str);
		return (iter);
	}
	return (-1);
}
