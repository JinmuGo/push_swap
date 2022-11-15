/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:38:45 by jgo               #+#    #+#             */
/*   Updated: 2022/11/12 20:29:58 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_s(va_list *ap, const char conversion)
{
	char	*arg;

	arg = va_arg(*ap, char *);
	if (!arg || conversion != STR)
		arg = "(null)";
	return (ft_putstr(arg));
}
