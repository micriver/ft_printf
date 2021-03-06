/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:52:47 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/28 09:45:41 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If Condition is true ? then value X : otherwise value Y
*/

int		ft_toupper(int c)
{
	return (c >= 'a' && c <= 'z' ? c - 32 : c);
}
