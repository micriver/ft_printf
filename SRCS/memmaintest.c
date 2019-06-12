/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmaintest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:23:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/11 19:42:07 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../libft/libft.h"

int 	main()
{
	char s[] = "bo"; 
	int width = 3;

	printf("%s\n", s);
	ft_memset(s, ' ', width);
	//printf("%s\n", ft_memset(s, 0, width));
	printf("%s\n", s);
	return(0);
}
