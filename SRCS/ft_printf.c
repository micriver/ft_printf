/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:01:13 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/07 10:39:47 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_printf.h"

void	ft_printf(const char *fmt, ...)
{
	va_list vl;
	char *buf;
	int i;
	int j;

	i = 0;
	buf = (char *)malloc(sizeof(char) * (ft_strlen(fmt)));
	va_start(vl, fmt);
	i = 0;
	j = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			break ;
		}
		else
			ft_strcpy(buf, fmt);
		i++;
	}
	ft_putstr(buf);
	va_end(vl);
}

int		main(void)
{
	ft_printf("whatup\n");
	return (0);
}