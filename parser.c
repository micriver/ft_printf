/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:21:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/02 15:29:33 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *fmt, ...)
{
	va_list args;
	int i;
	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			//***create an argument member in the struct!!!!***
			//OR CREATE A CLEAR BIT FUNCTION AND USE SAME STRUCTURE MEMBER FOR EACH FLAG EVERYTIME IT LOOPS
			i++;
			argstring = conversion(fmt, *i);
		}
		else if (fmt[i] == '%')
			ft_putchar('%');
		ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (0);
}
